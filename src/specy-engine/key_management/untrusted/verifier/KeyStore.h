#pragma once
#include "string.h"
#include "iostream"
#include <map>
#include <cppcodec/base64_default_rfc4648.hpp>
#include <third_party/json_lib/json11.hpp>
#include <utility>
#include <sgx_tcrypto.h>
#include <sgx_quote.h>
#include "common/utils/untrusted/common.h"
#include "CertUtils.h"

using json11::Json;
using std::map;

class KeyStore : public std::enable_shared_from_this<KeyStore>
{
    struct server_info
    {
        sgx_ec256_public_t public_key;

        explicit server_info(sgx_ec256_public_t pk) : public_key(pk) {}
    };

public:
    KeyStore() {}

    bool RegisterReport(const char *http_packet);

    const sgx_ec256_public_t &public_key() const
    {
        return self_public_;
    }

    const string &report() const
    {
        return self_report_;
    }

private:
    static ptr<bytes> ValidateVerificationReport(const char *http_packet);

    string self_report_;
    uint8_t self_public_rsa_;
    sgx_ec256_public_t self_public_;
};
