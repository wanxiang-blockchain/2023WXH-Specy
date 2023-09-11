#pragma once

#include <exception>
#include "common/utils/untrusted/openssl_exception.h"
#include "common/utils/untrusted/common.h"

bool VerifyCertsAndSignature(const string &certs, const bytes &sig, const uint8_t *data, size_t size);
