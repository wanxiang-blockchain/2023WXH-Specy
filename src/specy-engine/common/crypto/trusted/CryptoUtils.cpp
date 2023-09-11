#include "CryptoUtils.h"
#include "common/base64/base64.h"
#include "common/utils/trusted/utils.h"
#include "common/local_attestation/untrusted/UntrustedEnclaveMessageExchange.h"

int encrypt(sgx_aes_gcm_128bit_key_t *key,
            uint8_t *plain,
            uint32_t plain_len,
            uint8_t *cipher,
            uint32_t cipher_len)
{
    // create buffer
    uint32_t needed_size = plain_len + SGX_AESGCM_IV_SIZE + SGX_AESGCM_MAC_SIZE;
    assert(cipher_len >= needed_size);

    // gen rnd iv
    sgx_read_rand(cipher, SGX_AESGCM_IV_SIZE);

    // encrypt
    return sgx_rijndael128GCM_encrypt(key, plain, plain_len,
                                      cipher + SGX_AESGCM_IV_SIZE + SGX_AESGCM_MAC_SIZE, cipher, SGX_AESGCM_IV_SIZE, NULL, 0,
                                      (sgx_aes_gcm_128bit_tag_t *)(cipher + SGX_AESGCM_IV_SIZE));
}

int decrypt(sgx_aes_gcm_128bit_key_t *key,
            uint8_t *cipher,
            uint32_t cipher_len,
            uint8_t *plain,
            uint32_t plain_len)
{
    // create buffer
    uint32_t needed_size = cipher_len - SGX_AESGCM_IV_SIZE - SGX_AESGCM_MAC_SIZE;
    assert(plain_len >= needed_size);

    // decrypt
    return sgx_rijndael128GCM_decrypt(key,
                                      cipher + SGX_AESGCM_IV_SIZE + SGX_AESGCM_MAC_SIZE,          /* cipher */
                                      plain_len, plain,                                           /* plain out */
                                      cipher, SGX_AESGCM_IV_SIZE,                                 /* nonce */
                                      NULL, 0,                                                    /* aad */
                                      (sgx_aes_gcm_128bit_tag_t *)(cipher + SGX_AESGCM_IV_SIZE)); /* tag */
}

int get_random_bytes(uint8_t *buffer, size_t length)
{
    return sgx_read_rand(buffer, length);
}

int sign_challenge(string challenge, sgx_ec256_private_t *enclave_sk, sgx_ec256_signature_t *signature)
{
    const char *msg = challenge.c_str();
    // sgx_sha256_hash_t hash;

    // sgx_status_t ret = sgx_sha256_msg((const uint8_t *)msg, challenge.length(), &hash);

    sgx_ecc_state_handle_t ecc_handle;

    sgx_status_t status = sgx_ecc256_open_context(&ecc_handle);
    if (status != SGX_SUCCESS)
    {
        goto err;
    }

    uint8_t sig[sizeof(sgx_ec256_signature_t)];
    status = sgx_ecdsa_sign((const uint8_t *)msg, challenge.length(), enclave_sk, (sgx_ec256_signature_t*)sig, ecc_handle);
    //status = sgx_ecdsa_sign((uint8_t *)&hash, SGX_SHA256_HASH_SIZE, &temp_sk, signature, ecc_handle);
    if (status != SGX_SUCCESS)
        goto err;

    status = sgx_ecc256_close_context(ecc_handle);
    if (status != SGX_SUCCESS)
        goto err;

    bytes_swap(sig, 32);
    bytes_swap(sig + 32, 32);
    memcpy(signature, sig, sizeof(sgx_ec256_signature_t));

    return 0;

err:
    if (ecc_handle != NULL)
        sgx_ecc256_close_context(ecc_handle);
    return -1;
}

int validate_signature(const size_t challenge_size,
                       const uint8_t *challenge,
                       sgx_ec256_public_t *pk,
                       sgx_ec256_signature_t *sig)
{
    sgx_ecc_state_handle_t ecc_handle;

    sgx_status_t status = sgx_ecc256_open_context(&ecc_handle);
    if (status != SGX_SUCCESS)
        goto err;

    uint8_t result;
    status = sgx_ecdsa_verify(challenge, challenge_size, pk, sig, &result, ecc_handle);
    if (status != SGX_SUCCESS || result == SGX_EC_INVALID_SIGNATURE)
        goto err;

    status = sgx_ecc256_close_context(ecc_handle);
    if (status != SGX_SUCCESS)
        goto err;

    return 0;

err:
    if (ecc_handle != NULL)
        sgx_ecc256_close_context(ecc_handle);
    return -1;
}
