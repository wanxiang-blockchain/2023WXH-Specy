/usr/local/bin/protoc --version

/usr/local/bin/protoc --proto_path=. --cpp_out=./untrusted/ Regulator.proto
/usr/local/bin/protoc --proto_path=. --cpp_out=./untrusted/ Register.proto


/usr/local/bin/protoc --proto_path=. --grpc_out=./untrusted/ --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin Regulator.proto
/usr/local/bin/protoc --proto_path=. --grpc_out=./untrusted/ --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin Register.proto


# trusted protobuf generate instruction
/home/hongbo/protobuf/bin/protoc --proto_path=. --cpp_out=./trusted/binding_enclave Register.proto
/home/hongbo/protobuf/bin/protoc --proto_path=. --cpp_out=./trusted/binding_enclave Regulator.proto
/home/hongbo/protobuf/bin/protoc --proto_path=. --cpp_out=./trusted/binding_enclave BindingQuery.proto

/home/hongbo/protobuf/bin/protoc --proto_path=. --cpp_out=./trusted/e2e_message E2EMessage.proto
/home/hongbo/protobuf/bin/protoc --proto_path=. --cpp_out=./trusted/e2e_message RuleCheck.proto
/home/hongbo/protobuf/bin/protoc --proto_path=. --cpp_out=./trusted/e2e_message Signature.proto
/home/hongbo/protobuf/bin/protoc --proto_path=. --cpp_out=./trusted/rule_enclave EntityQuery.proto