#pragma once

#include <memory>
#include <iostream>
#include <thread>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "cppcodec/hex_default_lower.hpp"

#include "sgx_uae_launch.h"
#include "sgx_uae_epid.h"
#include "sgx_uae_quote_ex.h"
#include "common/utils/untrusted/sgx_exception.h"
#include "sgx_eid.h"
#include "common/utils/untrusted/common.h"
#include "common/utils/untrusted/secret.h"
#include "common/data_types/key_management/ErrorType.h"
KEYMANAGEMENT_ERROR_CODE GetEnclaveQuote(sgx_enclave_id_t enclave_id, uint8_t *pubkey, uint8_t *pubEncryptKey, std::shared_ptr<bytes> &quote_buffer_return);
