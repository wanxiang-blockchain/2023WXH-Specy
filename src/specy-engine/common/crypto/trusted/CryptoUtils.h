#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include "sgx_tcrypto.h"
#include "sgx_trts.h"

using namespace std;
// #include <openssl/x509.h>
// #include <stdint.h>

int sign_challenge(string challenge, sgx_ec256_private_t *enclave_sk, sgx_ec256_signature_t *signature);
int validate_signature(const size_t challenge_size,
                       const uint8_t *challenge,
                       sgx_ec256_public_t *pk,
                       sgx_ec256_signature_t *sig);
int encrypt(sgx_aes_gcm_128bit_key_t *key,
            uint8_t *plain,
            uint32_t plain_len,
            uint8_t *cipher,
            uint32_t cipher_len);
int decrypt(sgx_aes_gcm_128bit_key_t *key,
            uint8_t *cipher,
            uint32_t cipher_len,
            uint8_t *plain,
            uint32_t plain_len);
int get_random_bytes(uint8_t *buffer, size_t length);
