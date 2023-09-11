#include "common/base64/Transform.h"

string EncodeFromCharToString(const char *input, unsigned int len)
{
    return base64_encode(reinterpret_cast<const unsigned char *>(input), len);
}

extern string EncodeFromStringToString(const string &input)
{
    return base64_encode(reinterpret_cast<const unsigned char *>(input.c_str()), input.length());
}

string DecodeFromStringToString(const string &input)
{
    return base64_decode(input);
}

extern string DecodeFromCharToString(const char *input)
{
    string str = input;
    return base64_decode(input);
}