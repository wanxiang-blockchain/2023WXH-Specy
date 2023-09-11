// NOTE: 
// Do not try to use `ocall_print_string` in this .cpp file.
// Since `ocall_print_string` function is defined in 'UntrustedEnclaveMessageExchange.h',
// which has some same function declarations compared with this file. Compiler would fail.
#include "common/local_attestation/trusted/EnclaveMessageExchange.h"


#define MAX_SESSION_COUNT 16

//number of open sessions
uint32_t g_session_count = 0;
std::mutex mtx_gSessionCount;

uint32_t generate_session_id(uint32_t *session_id);

//Array of open session ids
session_id_tracker_t *g_session_id_tracker[MAX_SESSION_COUNT];
std::mutex mtx_gSessionIdTracker;

std::map<sgx_enclave_id_t, dh_session_t> g_src_session_info_map;
std::mutex mtx_gSrcSessionInfoMap;

//Map between the source enclave id and the session information associated with that particular session
std::map<sgx_enclave_id_t, dh_session_t> g_dest_session_info_map;
std::mutex mtx_gDestSessionInfoMap;

//Create a session with the destination enclave
uint32_t create_session(sgx_enclave_id_t src_enclave_id,
                        sgx_enclave_id_t dest_enclave_id,
                        dh_session_t *session_info)
{
    sgx_dh_msg1_t dh_msg1;   //Diffie-Hellman Message 1
    sgx_key_128bit_t dh_aek; // Session Key
    sgx_dh_msg2_t dh_msg2;   //Diffie-Hellman Message 2
    sgx_dh_msg3_t dh_msg3;   //Diffie-Hellman Message 3
    uint32_t session_id;
    uint32_t retstatus;
    sgx_status_t status = SGX_SUCCESS;
    sgx_dh_session_t sgx_dh_session;
    sgx_dh_session_enclave_identity_t responder_identity;

    if (!session_info)
    {
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }

    memset(&dh_aek, 0, sizeof(sgx_key_128bit_t));
    memset(&dh_msg1, 0, sizeof(sgx_dh_msg1_t));
    memset(&dh_msg2, 0, sizeof(sgx_dh_msg2_t));
    memset(&dh_msg3, 0, sizeof(sgx_dh_msg3_t));
    memset(session_info, 0, sizeof(dh_session_t));

    //Intialize the session as a session initiator
    status = sgx_dh_init_session(SGX_DH_SESSION_INITIATOR, &sgx_dh_session);
    if (SGX_SUCCESS != status)
    {
        return status;
    }

    //Ocall to request for a session with the destination enclave and obtain session id and Message 1 if successful
    status = ocall_session_request(&retstatus, src_enclave_id, dest_enclave_id, &dh_msg1, &session_id);
    if (status == SGX_SUCCESS)
    {
        if (retstatus != (uint32_t)kLA_SUCCESS)
            return (retstatus);
    }
    else
    {
        return (uint32_t)kLA_ATTESTATION_SE_ERROR;
    }
    //Process the message 1 obtained from desination enclave and generate message 2
    status = sgx_dh_initiator_proc_msg1(&dh_msg1, &dh_msg2, &sgx_dh_session);
    if (SGX_SUCCESS != status)
    {
        return status;
    }

    //Send Message 2 to Destination Enclave and get Message 3 in return
    status = ocall_exchange_report(&retstatus, src_enclave_id, dest_enclave_id, &dh_msg2, &dh_msg3, session_id);
    if (status == SGX_SUCCESS)
    {
        if (retstatus != (uint32_t)kLA_SUCCESS)
            return (retstatus);
    }
    else
    {
        return (uint32_t)kLA_ATTESTATION_SE_ERROR;
    }

    //Process Message 3 obtained from the destination enclave
    status = sgx_dh_initiator_proc_msg3(&dh_msg3, &sgx_dh_session, &dh_aek, &responder_identity);
    if (SGX_SUCCESS != status)
    {
        return status;
    }

    // Verify the identity of the destination enclave
    if (verify_peer_enclave_trust(&responder_identity) != (uint32_t)kLA_SUCCESS)
    {
        return (uint32_t)kLA_INVALID_SESSION;
    }

    memcpy(session_info->active.AEK, &dh_aek, sizeof(sgx_key_128bit_t));
    session_info->session_id = session_id;
    session_info->active.counter = 0;
    session_info->status = ACTIVE;
    memset(&dh_aek, 0, sizeof(sgx_key_128bit_t));
    return status;
}

//Handle the request from Source Enclave for a session
uint32_t ecall_session_request(sgx_enclave_id_t src_enclave_id,
                               sgx_dh_msg1_t *dh_msg1,
                               uint32_t *session_id)
{
    dh_session_t session_info;
    sgx_dh_session_t sgx_dh_session;
    sgx_status_t status = SGX_SUCCESS;

    if (!session_id || !dh_msg1)
    {
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }
    //Intialize the session as a session responder
    status = sgx_dh_init_session(SGX_DH_SESSION_RESPONDER, &sgx_dh_session);
    if (SGX_SUCCESS != status)
    {
        return status;
    }

    //get a new SessionID
    if ((status = (sgx_status_t)generate_session_id(session_id)) != (uint32_t)kLA_SUCCESS)
        return status; //no more sessions available

    //Allocate memory for the session id tracker
    mtx_gSessionIdTracker.lock();
    g_session_id_tracker[*session_id] = (session_id_tracker_t *)malloc(sizeof(session_id_tracker_t));
    if (!g_session_id_tracker[*session_id])
    {
        SAFE_FREE(g_session_id_tracker[*session_id]);
        mtx_gSessionIdTracker.unlock();
        return (uint32_t)kLA_MALLOC_ERROR;
    }

    memset(g_session_id_tracker[*session_id], 0, sizeof(session_id_tracker_t));
    g_session_id_tracker[*session_id]->session_id = *session_id;
    session_info.status = IN_PROGRESS;
    mtx_gSessionIdTracker.unlock();

    //Generate Message1 that will be returned to Source Enclave
    status = sgx_dh_responder_gen_msg1((sgx_dh_msg1_t *)dh_msg1, &sgx_dh_session);
    if (SGX_SUCCESS != status)
    {
        SAFE_FREE(g_session_id_tracker[*session_id]);
        return status;
    }
    memcpy(&session_info.in_progress.dh_session, &sgx_dh_session, sizeof(sgx_dh_session_t));
    
    mtx_gDestSessionInfoMap.lock();
    //Store the session information under the correspoding source enlave id key
    g_dest_session_info_map.insert(std::pair<sgx_enclave_id_t, dh_session_t>(src_enclave_id, session_info));
    mtx_gDestSessionInfoMap.unlock();

    return status;
}

//Verify Message 2, generate Message3 and exchange Message 3 with Source Enclave
uint32_t ecall_exchange_report(sgx_enclave_id_t src_enclave_id,
                               sgx_dh_msg2_t *dh_msg2,
                               sgx_dh_msg3_t *dh_msg3,
                               uint32_t session_id)
{

    sgx_key_128bit_t dh_aek; // Session key
    dh_session_t *session_info;
    uint32_t status = (uint32_t)kLA_SUCCESS;
    sgx_dh_session_t sgx_dh_session;
    sgx_dh_session_enclave_identity_t initiator_identity;

    if (!dh_msg2 || !dh_msg3)
    {
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }

    memset(&dh_aek, 0, sizeof(sgx_key_128bit_t));
    do
    {
        mtx_gDestSessionInfoMap.lock();
        //Retreive the session information for the corresponding source enclave id
        std::map<sgx_enclave_id_t, dh_session_t>::iterator it = g_dest_session_info_map.find(src_enclave_id);
        if (it != g_dest_session_info_map.end())
        {
            session_info = &it->second;
        }
        else
        {
            mtx_gDestSessionInfoMap.unlock();
            status = (uint32_t)kLA_INVALID_SESSION;
            break;
        }
        mtx_gDestSessionInfoMap.unlock();

        if (session_info->status != IN_PROGRESS)
        {
            status = (uint32_t)kLA_INVALID_SESSION;
            break;
        }

        memcpy(&sgx_dh_session, &session_info->in_progress.dh_session, sizeof(sgx_dh_session_t));

        dh_msg3->msg3_body.additional_prop_length = 0;
        //Process message 2 from source enclave and obtain message 3
        sgx_status_t se_ret = sgx_dh_responder_proc_msg2(dh_msg2,
                                                         dh_msg3,
                                                         &sgx_dh_session,
                                                         &dh_aek,
                                                         &initiator_identity);
        if (SGX_SUCCESS != se_ret)
        {
            status = se_ret;
            break;
        }

        //Verify source enclave's trust
        if (verify_peer_enclave_trust(&initiator_identity) != (uint32_t)kLA_SUCCESS)
        {
            return (uint32_t)kLA_INVALID_SESSION;
        }

        //save the session ID, status and initialize the session nonce
        session_info->session_id = session_id;
        session_info->status = ACTIVE;
        session_info->active.counter = 0;
        memcpy(session_info->active.AEK, &dh_aek, sizeof(sgx_key_128bit_t));
        memset(&dh_aek, 0, sizeof(sgx_key_128bit_t));
        mtx_gSessionCount.lock();
        g_session_count++;
        mtx_gSessionCount.unlock();
    } while (0);

    if (status != (uint32_t)kLA_SUCCESS)
    {
        ecall_end_session(src_enclave_id);
    }

    return status;
}

//Request for the response size, send the request message to the destination enclave and receive the response message back
uint32_t send_request_receive_response(sgx_enclave_id_t src_enclave_id,
                                       sgx_enclave_id_t dest_enclave_id,
                                       dh_session_t *session_info,
                                       char *inp_buff,
                                       size_t inp_buff_len,
                                       size_t max_out_buff_size,
                                       char **out_buff,
                                       size_t *out_buff_len)
{
    const uint8_t *plaintext;
    uint32_t plaintext_length;
    sgx_status_t status;
    uint32_t retstatus;
    secure_message_t *req_message;
    secure_message_t *resp_message;
    uint8_t *decrypted_data;
    uint32_t decrypted_data_length;
    uint32_t plain_text_offset;
    uint8_t l_tag[TAG_SIZE];
    plaintext = (const uint8_t *)(" ");
    plaintext_length = 0;

    ocall_print_string("enter send request receive response", __FILE__, __LINE__);
    
    if (!session_info || !inp_buff)
    {
        ocall_print_string("exit send request receive response INVALID_PARAMETER_ERROR", __FILE__, __LINE__);
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }
    
    //Check if the nonce for the session has not exceeded 2^32-2 if so end session and start a new session
    if (session_info->active.counter == ((uint32_t)-2))
    {
        close_session(src_enclave_id, dest_enclave_id);
        create_session(src_enclave_id, dest_enclave_id, session_info);
    }
    //Allocate memory for the AES-GCM request message
    req_message = (secure_message_t *)malloc(sizeof(secure_message_t) + inp_buff_len);
    if (!req_message)
    {
        SAFE_FREE(req_message);
        ocall_print_string("exit send request receive response MALLOC_ERROR_1", __FILE__, __LINE__);
        return (uint32_t)kLA_MALLOC_ERROR;
    }   

    memset(req_message, 0, sizeof(secure_message_t) + inp_buff_len);
    const uint32_t data2encrypt_length = (uint32_t)inp_buff_len;

    //Set the payload size to data to encrypt length
    req_message->message_aes_gcm_data.payload_size = data2encrypt_length;

    //Use the session nonce as the payload IV
    memcpy(req_message->message_aes_gcm_data.reserved, &session_info->active.counter, sizeof(session_info->active.counter));
    
    //Set the session ID of the message to the current session id
    req_message->session_id = session_info->session_id;

    //Prepare the request message with the encrypted payload
    status = sgx_rijndael128GCM_encrypt(&session_info->active.AEK, (uint8_t *)inp_buff, data2encrypt_length,
                                        req_message->message_aes_gcm_data.payload,
                                        req_message->message_aes_gcm_data.reserved,
                                        sizeof(req_message->message_aes_gcm_data.reserved), plaintext, plaintext_length,
                                        &(req_message->message_aes_gcm_data.payload_tag));
    if (SGX_SUCCESS != status)
    {
        SAFE_FREE(req_message);
        ocall_print_string("exit send request receive response SGX Call Not Success", __FILE__, __LINE__);
        return status;
    }

    //Allocate memory for the response message
    resp_message = (secure_message_t *)malloc(sizeof(secure_message_t) + max_out_buff_size);
    if (!resp_message)
    {
        SAFE_FREE(req_message);
        SAFE_FREE(resp_message);
        ocall_print_string("exit send request receive response MALLOC_ERROR_3", __FILE__, __LINE__);
        return (uint32_t)kLA_MALLOC_ERROR;
    }
    memset(resp_message, 0, sizeof(secure_message_t) + max_out_buff_size);

    //Ocall to send the request to the Destination Enclave and get the response message back
    status = ocall_send_request(&retstatus, src_enclave_id, dest_enclave_id, req_message,
                                (sizeof(secure_message_t) + inp_buff_len), max_out_buff_size,
                                resp_message, (sizeof(secure_message_t) + max_out_buff_size));
    SAFE_FREE(req_message);
    if (status == SGX_SUCCESS)
    {
        if (retstatus != (uint32_t)kLA_SUCCESS)
        {
            SAFE_FREE(resp_message);
            ocall_print_string("exit send request receive response Function Not Success", __FILE__, __LINE__);
            return (retstatus);
        }
    }
    else
    {
        ocall_print_string("ocall_send_request::status", __FILE__, status);
        SAFE_FREE(resp_message);
        ocall_print_string("exit send request receive response SGX Call Not Success", __FILE__, __LINE__);
        return (uint32_t)kLA_ATTESTATION_SE_ERROR;
    }
    
    //Code to process the response message from the Destination Enclave

    decrypted_data_length = resp_message->message_aes_gcm_data.payload_size;
    plain_text_offset = decrypted_data_length;
    decrypted_data = (uint8_t *)malloc(decrypted_data_length);
    if (!decrypted_data)
    {
        SAFE_FREE(resp_message);
        SAFE_FREE(decrypted_data);
        ocall_print_string("exit send request receive response MALLOC_ERROR_4", __FILE__, __LINE__);
        return (uint32_t)kLA_MALLOC_ERROR;
    }
    memset(&l_tag, 0, 16);

    memset(decrypted_data, 0, decrypted_data_length);

    //Decrypt the response message payload
    status = sgx_rijndael128GCM_decrypt(&session_info->active.AEK, resp_message->message_aes_gcm_data.payload,
                                        decrypted_data_length, decrypted_data,
                                        resp_message->message_aes_gcm_data.reserved,
                                        sizeof(resp_message->message_aes_gcm_data.reserved), &(resp_message->message_aes_gcm_data.payload[plain_text_offset]), plaintext_length,
                                        &resp_message->message_aes_gcm_data.payload_tag);

    if (SGX_SUCCESS != status)
    {
        SAFE_FREE(decrypted_data);
        SAFE_FREE(resp_message);
        ocall_print_string("exit send request receive response SGX Call Not Success", __FILE__, __LINE__);
        return status;
    }

    // Verify if the nonce obtained in the response is equal to the session nonce + 1 (Prevents replay attacks)
    // TODO (Xufei) We do not +1 here temporarily, just for demo. Should be modified once counter becomes multi-thread safe
    // if (*(reinterpret_cast<uint32_t *>(resp_message->message_aes_gcm_data.reserved)) != (session_info->active.counter + 1))
    if (*(reinterpret_cast<uint32_t *>(resp_message->message_aes_gcm_data.reserved)) != (session_info->active.counter))
    {
        SAFE_FREE(resp_message);
        SAFE_FREE(decrypted_data);
        ocall_print_string("exit send request receive response PARAMETER_ERROR", __FILE__, __LINE__);
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }

    // TODO: Need to consider multi-threads situation when updating counter.
    //Update the value of the session nonce in the source enclave
    // session_info->active.counter = session_info->active.counter + 1;

    SAFE_FREE(resp_message);

    //Allocate memory for the response payload to be copied
    *out_buff = (char *)malloc(max_out_buff_size);
    if (!*out_buff)
    {
        SAFE_FREE(*out_buff);
        SAFE_FREE(decrypted_data);
        ocall_print_string("exit send request receive response MALLOC_ERROR_2", __FILE__, __LINE__);
        return (uint32_t)kLA_MALLOC_ERROR;
    }
    memset(*out_buff, 0, max_out_buff_size);

    memcpy(out_buff_len, &decrypted_data_length, sizeof(decrypted_data_length));
    memcpy(*out_buff, (char *)decrypted_data, decrypted_data_length);

    SAFE_FREE(decrypted_data);

    ocall_print_string("exit send request receive response", __FILE__, __LINE__);
    return (uint32_t)kLA_SUCCESS;
}

//Process the request from the Source enclave and send the response message back to the Source enclave
uint32_t ecall_generate_response(sgx_enclave_id_t src_enclave_id,
                                 secure_message_t *req_message,
                                 size_t req_message_size,
                                 size_t max_payload_size,
                                 secure_message_t *resp_message,
                                 size_t resp_message_size)
{
    const uint8_t *plaintext;
    uint32_t plaintext_length;
    uint8_t *decrypted_data;
    uint32_t decrypted_data_length;
    uint32_t plain_text_offset;
    ms_in_msg_exchange_t *ms;
    size_t resp_data_length;
    size_t resp_message_calc_size;
    char *resp_data;
    uint8_t l_tag[TAG_SIZE];
    size_t header_size, expected_payload_size;
    dh_session_t *session_info;
    secure_message_t *temp_resp_message;
    uint32_t ret;
    sgx_status_t status;

    ocall_print_string("enter ecall generate response", __FILE__, __LINE__);
    plaintext = (const uint8_t *)(" ");
    plaintext_length = 0;

    //ocall_print_string("generate_response");
    //ocall_print_string("src_enlave_id");
    //ocall_print_string(std::to_string((unsigned long)src_enclave_id).c_str());
    if (!req_message || !resp_message)
    {
        ocall_print_string("exit ecall generate response::INVALID_PARAMETER_ERROR", __FILE__, __LINE__);
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }

    mtx_gDestSessionInfoMap.lock();
    //Get the session information from the map corresponding to the source enclave id
    std::map<sgx_enclave_id_t, dh_session_t>::iterator it = g_dest_session_info_map.find(src_enclave_id);
    if (it != g_dest_session_info_map.end())
    {
        session_info = &it->second;
    }
    else
    {
        mtx_gDestSessionInfoMap.unlock();
        ocall_print_string("exit ecall generate response::INVALID_SESSION", __FILE__, __LINE__);
        return (uint32_t)kLA_INVALID_SESSION;
    }
    mtx_gDestSessionInfoMap.unlock();

    if (session_info->status != ACTIVE)
    {
        ocall_print_string("exit ecall generate response::INVALID_SESSION", __FILE__, __LINE__);
        return (uint32_t)kLA_INVALID_SESSION;
    }

    //Set the decrypted data length to the payload size obtained from the message
    decrypted_data_length = req_message->message_aes_gcm_data.payload_size;

    header_size = sizeof(secure_message_t);
    expected_payload_size = req_message_size - header_size;

    //Verify the size of the payload
    if (expected_payload_size != decrypted_data_length) {
        ocall_print_string("exit ecall generate response::INVALID_PARAMETER_ERROR", __FILE__, __LINE__);
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }
        

    memset(&l_tag, 0, 16);
    plain_text_offset = decrypted_data_length;
    decrypted_data = (uint8_t *)malloc(decrypted_data_length);
    if (!decrypted_data)
    {
        SAFE_FREE(decrypted_data);
        ocall_print_string("exit ecall generate response::MALLOC_ERROR", __FILE__, __LINE__);
        return (uint32_t)kLA_MALLOC_ERROR;
    }

    memset(decrypted_data, 0, decrypted_data_length);

    //Decrypt the request message payload from source enclave
    status = sgx_rijndael128GCM_decrypt(&session_info->active.AEK, req_message->message_aes_gcm_data.payload,
                                        decrypted_data_length, decrypted_data,
                                        req_message->message_aes_gcm_data.reserved,
                                        sizeof(req_message->message_aes_gcm_data.reserved), 
                                        &(req_message->message_aes_gcm_data.payload[plain_text_offset]), plaintext_length,
                                        &req_message->message_aes_gcm_data.payload_tag);
    if (SGX_SUCCESS != status)
    {
        ocall_print_string("exit ecall generate response::SGX Failed", __FILE__, __LINE__);
        SAFE_FREE(decrypted_data);
        return status;
    }

    //Casting the decrypted data to the marshaling structure type to obtain type of request (generic message exchange/enclave to enclave call)
    ms = (ms_in_msg_exchange_t *)decrypted_data;

    // Verify if the nonce obtained in the request is equal to the session nonce
    // Note: We have removed check for nonce over (2 ^ 32) - 2 = 32. Have no idea what it's for. 
    // Note: If we encounter some problems in the future, may consider about this.
    // if ((uint32_t) * (req_message->message_aes_gcm_data.reserved) != session_info->active.counter || *(req_message->message_aes_gcm_data.reserved) > ((2 ^ 32) - 2))
    if (*(reinterpret_cast<uint32_t *>(req_message->message_aes_gcm_data.reserved)) != session_info->active.counter )
    {
        SAFE_FREE(decrypted_data);
        ocall_print_string("exit ecall generate response::INVALID_NONCE_ERROR", __FILE__, __LINE__);
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }

    if (ms->msg_type == MESSAGE_EXCHANGE)
    {
        //Call the generic secret response generator for message exchange
        ret = message_exchange_response_generator((char *)decrypted_data, &resp_data, &resp_data_length);
        if (ret != 0)
        {
            SAFE_FREE(resp_data);
            SAFE_FREE(decrypted_data);
            ocall_print_string("exit ecall generate response::INVALID_SESSION", __FILE__, __LINE__);
            return (uint32_t)kLA_INVALID_SESSION;
        }
    }
    else if (ms->msg_type == ENCLAVE_TO_ENCLAVE_CALL)
    {
        //Call the destination enclave's dispatcher to call the appropriate function in the destination enclave
        ret = enclave_to_enclave_call_dispatcher((char *)decrypted_data, decrypted_data_length, &resp_data, &resp_data_length);
        if (ret != 0)
        {
            SAFE_FREE(resp_data);
            SAFE_FREE(decrypted_data);
            ocall_print_string("exit ecall generate response::INVALID_SESSION", __FILE__, __LINE__);
            return (uint32_t)kLA_INVALID_SESSION;
        }
    }
    else
    {
        SAFE_FREE(decrypted_data);
        ocall_print_string("exit ecall generate response::INVALID_REQUEST_TYPE_ERROR", __FILE__, __LINE__);
        return (uint32_t)kLA_INVALID_REQUEST_TYPE_ERROR;
    }
    SAFE_FREE(decrypted_data);

    if (resp_data_length > max_payload_size)
    {
        SAFE_FREE(resp_data);
        ocall_print_string("exit ocall generate response::OUT_BUFFER_LENGTH_ERROR", __FILE__, __LINE__);
        return (uint32_t)kLA_OUT_BUFFER_LENGTH_ERROR;
    }

    resp_message_calc_size = sizeof(secure_message_t) + resp_data_length;

    if (resp_message_calc_size > resp_message_size)
    {
        SAFE_FREE(resp_data);
        ocall_print_string("exit ocall generate response::OUT_BUFFER_LENGTH_ERROR", __FILE__, __LINE__);
        return (uint32_t)kLA_OUT_BUFFER_LENGTH_ERROR;
    }

    //Code to build the response back to the Source Enclave
    temp_resp_message = (secure_message_t *)malloc(resp_message_calc_size);
    if (!temp_resp_message)
    {
        SAFE_FREE(resp_data);
        SAFE_FREE(temp_resp_message);
        ocall_print_string("exit ocall generate response::MALLOC_ERROR", __FILE__, __LINE__);
        return (uint32_t)kLA_MALLOC_ERROR;
    }
    memset(temp_resp_message, 0, resp_message_calc_size);
    const uint32_t data2encrypt_length = (uint32_t)resp_data_length;
    temp_resp_message->session_id = session_info->session_id;
    temp_resp_message->message_aes_gcm_data.payload_size = data2encrypt_length;

    // TODO (Xufei) Need to consider multi-threads situation
    //Increment the Session Nonce (Replay Protection)
    // session_info->active.counter = session_info->active.counter + 1;

    //Set the response nonce as the session nonce
    memcpy(temp_resp_message->message_aes_gcm_data.reserved, &session_info->active.counter, sizeof(session_info->active.counter));

    //Prepare the response message with the encrypted payload
    status = sgx_rijndael128GCM_encrypt(&session_info->active.AEK, (uint8_t *)resp_data, data2encrypt_length,
                                        temp_resp_message->message_aes_gcm_data.payload,
                                        temp_resp_message->message_aes_gcm_data.reserved,
                                        sizeof(temp_resp_message->message_aes_gcm_data.reserved), plaintext, plaintext_length,
                                        &(temp_resp_message->message_aes_gcm_data.payload_tag));
    SAFE_FREE(resp_data);
    if (SGX_SUCCESS != status)
    {
        SAFE_FREE(temp_resp_message);
        ocall_print_string("exit ocall generate response::SGX Failed", __FILE__, __LINE__);
        return status;
    }
    memset(resp_message, 0, sizeof(secure_message_t) + resp_data_length);
    memcpy(resp_message, temp_resp_message, sizeof(secure_message_t) + resp_data_length);

    SAFE_FREE(temp_resp_message);

    return (uint32_t)kLA_SUCCESS;
}

//Close a current session
uint32_t close_session(sgx_enclave_id_t src_enclave_id,
                       sgx_enclave_id_t dest_enclave_id)
{
    sgx_status_t status;

    uint32_t retstatus;

    //Ocall to ask the destination enclave to end the session
    status = ocall_end_session(&retstatus, src_enclave_id, dest_enclave_id);
    if (status == SGX_SUCCESS)
    {
        if (retstatus != (uint32_t)kLA_SUCCESS)
            return (retstatus);
    }
    else
    {
        return (uint32_t)kLA_ATTESTATION_SE_ERROR;
    }
    return (uint32_t)kLA_SUCCESS;
}

//Respond to the request from the Source Enclave to close the session
uint32_t ecall_end_session(sgx_enclave_id_t src_enclave_id)
{
    uint32_t status = (uint32_t)kLA_SUCCESS;
    int i;
    dh_session_t session_info;
    uint32_t session_id;

    mtx_gDestSessionInfoMap.lock();
    //Get the session information from the map corresponding to the source enclave id
    std::map<sgx_enclave_id_t, dh_session_t>::iterator it = g_dest_session_info_map.find(src_enclave_id);
    if (it != g_dest_session_info_map.end())
    {
        session_info = it->second;
    }
    else
    {
        mtx_gDestSessionInfoMap.unlock();
        return (uint32_t)kLA_INVALID_SESSION;
    }

    session_id = session_info.session_id;
    //Erase the session information for the current session
    g_dest_session_info_map.erase(src_enclave_id);
    mtx_gDestSessionInfoMap.unlock();

    //Update the session id tracker
    mtx_gSessionCount.lock();
    if (g_session_count > 0)
    {
        mtx_gSessionIdTracker.lock();
        //check if session exists
        for (i = 1; i <= MAX_SESSION_COUNT; i++)
        {
            if (g_session_id_tracker[i - 1] != NULL && g_session_id_tracker[i - 1]->session_id == session_id)
            {
                memset(g_session_id_tracker[i - 1], 0, sizeof(session_id_tracker_t));
                SAFE_FREE(g_session_id_tracker[i - 1]);
                g_session_count--;
                break;
            }
        }
        mtx_gSessionIdTracker.unlock();
    }
    mtx_gSessionCount.unlock();

    return status;
}

//Returns a new sessionID for the source destination session
uint32_t generate_session_id(uint32_t *session_id)
{
    uint32_t status = (uint32_t)kLA_SUCCESS;

    if (!session_id)
    {
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }
    
    mtx_gSessionIdTracker.lock();
    //if the session structure is untintialized, set that as the next session ID
    for (int i = 0; i < MAX_SESSION_COUNT; i++)
    {
        if (g_session_id_tracker[i] == NULL)
        {
            *session_id = i;
            mtx_gSessionIdTracker.unlock();
            return status;
        }
    }
    mtx_gSessionIdTracker.unlock();

    status = (uint32_t)kLA_NO_AVAILABLE_SESSION_ERROR;

    return status;
}

//Makes use of the sample code function to establish a secure channel with the destination enclave
uint32_t ecall_create_session(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id)
{
    uint32_t ke_status = (uint32_t)kLA_SUCCESS;
    dh_session_t dest_session_info;
    //Core reference code function for creating a session
    ke_status = create_session(src_enclave_id, dest_enclave_id, &dest_session_info);
    if (ke_status == (uint32_t)kLA_SUCCESS)
    {
        //Insert the session information into the map under the corresponding destination enclave id
        g_src_session_info_map.insert(std::pair<sgx_enclave_id_t, dh_session_t>(dest_enclave_id, dest_session_info));
    }
    memset(&dest_session_info, 0, sizeof(dh_session_t));
    return ke_status;
}

//Makes use of the sample code function to close a current session
uint32_t ecall_close_session(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id)
{
    dh_session_t dest_session_info;
    ATTESTATION_STATUS ke_status = (uint32_t)kLA_SUCCESS;

    mtx_gSrcSessionInfoMap.lock();
    //Search the map for the session information associated with the destination enclave id passed in
    std::map<sgx_enclave_id_t, dh_session_t>::iterator it = g_src_session_info_map.find(dest_enclave_id);
    if (it != g_src_session_info_map.end())
    {
        dest_session_info = it->second;
    }
    else
    {
        mtx_gSrcSessionInfoMap.unlock();
        return NULL;
    }
    //Core reference code function for closing a session
    ke_status = close_session(src_enclave_id, dest_enclave_id);

    //Erase the session information associated with the destination enclave id
    g_src_session_info_map.erase(dest_enclave_id);
    mtx_gSrcSessionInfoMap.unlock();
    return ke_status;
}