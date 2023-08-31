// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file includes head files.

#pragma once

#include <map>
#include <stdlib.h> // for malloc etc
#include <string>
#include <cstring>
#include <assert.h>

#include "sgx_utils.h"
#include "sgx_key.h"
#include "sgx_tcrypto.h"
#include "sgx_trts.h"
#include "sgx_thread.h"
#include "sgx_dh.h"

#include "common/data_types/local_attestation/ErrorType.h"
#include "common/data_types/key_management/ErrorType.h"
#include "common/base64/base64.h"
#include "common/crypto/trusted/CryptoUtils.h"
#include "common/local_attestation/trusted/RequestResponseUtil.h"
#include "common/local_attestation/trusted/EnclaveMessageExchange.h"
#include "common/local_attestation/trusted/Utility.h"
#include "common/utils/trusted/utils.h"

#include "protos/trusted/e2e_message/E2EMessage.pb.h"
#include "protos/trusted/e2e_message/Signature.pb.h"
#include "KeyManagementEnclave_t.h"


/* For SGX SSL support */
// #include <openssl/rsa.h>
// #include <openssl/err.h>
// #include <openssl/pem.h>
// #include <openssl/evp.h>