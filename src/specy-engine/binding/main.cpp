#include <BindingQuery.h>
#include <BindingEnclave_u.h>
// #include <BindingResolver.h>
#include <Transform.h>
#include "sgx_urts.h"

#include <common/data_types/binding/ErrorType.h>

using namespace std;
// using namespace antlr4;

static const unsigned long kMaxOutSize = 8192UL;



void mockProofRequest_withOneEvent(request_proto::ProofRequest* request) {
  request->set_chaintype("cosmos");
  request->set_chainid("1");
  request->set_height(1);
  request->set_txhash("0x12345678");
  request->set_txindex(1);

  // add Data 
  request_proto::TxMetaData* meta = new request_proto::TxMetaData();
  meta->set_fromaddress("0x1");
  meta->set_toaddress("0xf");
  meta->set_value(100);

  request_proto::Data* data = new request_proto::Data();
  data->set_allocated_meta(meta);

  request_proto::ContractEvent* contractEvent = data->add_events();
  contractEvent->set_contractid("bank");
  request_proto::Event* event = contractEvent->add_events();
  event->set_eventname("Transfer");
  request->set_allocated_data(data);
}

void mockProofRequest_withTwoEvents(request_proto::ProofRequest* request) {
  request->set_chaintype("cosmos");
  request->set_chainid("1");
  request->set_height(1);
  request->set_txhash("0x12345678");
  request->set_txindex(1);

  // add Data 
  request_proto::TxMetaData* meta = new request_proto::TxMetaData();
  meta->set_fromaddress("0x1");
  meta->set_toaddress("0xf");
  meta->set_value(100);

  request_proto::Data* data = new request_proto::Data();
  data->set_allocated_meta(meta);

  request_proto::ContractEvent* contractEvent = data->add_events();
  contractEvent->set_contractid("bank");
  request_proto::Event* event = contractEvent->add_events();
  event->set_eventname("Transfer");

  event = contractEvent->add_events();
  event->set_eventname("Approve");
  request->set_allocated_data(data);
}


uint32_t loadEnclave(string enclaveName, sgx_enclave_id_t* enclaveID) {
  return sgx_create_enclave(enclaveName.c_str(), SGX_DEBUG_FLAG,
                                NULL, NULL, enclaveID, NULL);
}


// used to test basic antlr parser
int main(int argc, const char* argv[]) {

  sgx_enclave_id_t bindingEnclaveID;
  string bindingEnclaveName = "binding_enclave.signed.so";
  BINDING_ERROR_CODE errorCode;

  request_proto::ProofRequest* oneEventMockRequest = new request_proto::ProofRequest();
  request_proto::ProofRequest* twoEventMockRequest = new request_proto::ProofRequest();

  mockProofRequest_withOneEvent(oneEventMockRequest);
  mockProofRequest_withTwoEvents(twoEventMockRequest);

  string mockString1 = oneEventMockRequest->SerializeAsString();
  cout<< "mockString1:  " << mockString1 << endl;

  string mockString2 = twoEventMockRequest->SerializeAsString();
  cout<< "mockString2:  " << mockString2 << endl;

  string base64MockString1 = EncodeFromStringToString(mockString1);
  string base64MockString2 = EncodeFromStringToString(mockString2);

  if (loadEnclave(bindingEnclaveName.c_str(), &bindingEnclaveID) != 0) {
    cout <<"Error: load enclave failed! " << endl;
  }

  char *output_char = (char *)malloc(kMaxOutSize);
  cout << "\n*********** Test1 one event in proof request start*************\n";
  ecall_process_proof_request(bindingEnclaveID, &errorCode, base64MockString1.c_str(), kMaxOutSize, output_char, kMaxOutSize);
  cout << "\n*********** Test1 one event in proof request end*************\n";

  cout << "\n*********** Test2 two event in proof request start*************\n";
  ecall_process_proof_request(bindingEnclaveID, &errorCode, base64MockString2.c_str(), kMaxOutSize, output_char, kMaxOutSize);
  cout << "\n*********** Test2 two event in proof request end*************\n";


  return 0;
}
