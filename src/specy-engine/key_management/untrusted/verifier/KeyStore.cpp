#include "KeyStore.h"

bool KeyStore::RegisterReport(const char *http_packet)
{
    if (!self_report_.empty())
    {
        throw std::runtime_error("Key Store has been registered");
    }
    // std::cout << "report 1" << std::endl;
    auto quote_bytes = ValidateVerificationReport(http_packet);
    if (quote_bytes == nullptr)
    {
        return false;
    }
    return true;
}

string url_decode_http(const char *start, const char *end)
{
    string output;
    output.reserve((end - start + 1) * sizeof(char));

    const char *ptr = start;
    while (*ptr && ptr < end)
    {
        if (*ptr == '%')
        {
            char buffer[3] = {ptr[1], ptr[2], 0};
            output.push_back((char)strtol(buffer, nullptr, 16));
            ptr += 3;
        }
        else
        {
            output.push_back(*ptr);
            ptr++;
        }
    }

    return output;
}

ptr<bytes> KeyStore::ValidateVerificationReport(const char *http_packet)
{
    const char *header_length = "Content-Length: ";
    const char *header_signature = "X-IASReport-Signature: ";
    const char *header_certificates = "X-IASReport-Signing-Certificate: ";
    const char *double_delimiter = "\r\n\r\n";
    const char *delimiter = "\r\n";

    char *ptr_l, *ptr_r;

    // Parse Content-Length
    std::cout << "report 2" << std::endl;
    ptr_l = (char *)(strstr(http_packet, header_length) + strlen(header_length));
    size_t content_length = strtoul(ptr_l, nullptr, 10);
    std::cout << "report 3" << std::endl;
    // Parse IASReport-Signature
    ptr_l = (char *)(strstr(http_packet, header_signature) + strlen(header_signature));
    ptr_r = (char *)(strstr(ptr_l, delimiter));
    bytes signature = base64::decode(ptr_l, ptr_r - ptr_l);
    // std::cout << "report 4" << std::endl;
    // Parse IASReport-Signing-Certificate
    ptr_l = (char *)(strstr(http_packet, header_certificates) + strlen(header_certificates));
    ptr_r = (char *)(strstr(ptr_l, delimiter));
    string certificates = url_decode_http((const char *)ptr_l, (const char *)ptr_r);
    // std::cout << "report 5" << std::endl;
    // Parse response body
    ptr_l = (char *)(strstr(http_packet, double_delimiter) + strlen(double_delimiter));
    string parse_error;
    Json body = Json::parse(ptr_l, parse_error);

    // Verify Certificates and Signature
    bool result;
    try
    {
        result = VerifyCertsAndSignature(certificates,
                                         signature,
                                         reinterpret_cast<const uint8_t *>(ptr_l),
                                         content_length);
    }
    catch (OpenSSLException &ex)
    {
        return nullptr;
    }
    if (!result || !parse_error.empty())
    {
        return nullptr;
    }

#if 0
    {
        "id": "106582804461982983826361650412833082065",
        "timestamp": "2019-11-13T15:37:33.882837",
        "version": 3,
        "isvEnclaveQuoteStatus": "OK",
        "isvEnclaveQuoteBody": "AgAAAFQLAAAIAAcAAAAAAG5efDZ1P3juuVBseEtuC4eOQ2ZklBH+BDSnXK+REv4iBgYCBAGAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABwAAAAAAAAAHAAAAAAAAALFP1Bby2HTBUNgjVO0JylCBQo+FCqLdX3fhLIEpuuQMAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB+QRJPiJjE8HTUxZyvS+TfHWpfAyoA3gRijfU5KA7dBwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADf6oCPPd/bA48OU6gGmYtwJoacI+M3HEQXM91TZHbZQ8TRkZOtEH1JDlhfKZ1RAFpZVLN1So+BJmMX4xwk/AmH"
    }
#endif

    if (body["version"].int_value() != 3)
    {
        return nullptr;
    }

    if (body["isvEnclaveQuoteStatus"].string_value() != string("OK"))
    {
        return nullptr;
    }

    return make_shared<bytes>(base64::decode(body["isvEnclaveQuoteBody"].string_value()));
}
