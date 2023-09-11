#pragma once

#include <string>
#include "base64.h"

using namespace std;

extern string EncodeFromCharToString(const char* input, unsigned int len);

extern string EncodeFromStringToString(const string &input);

extern string DecodeFromStringToString(const string &input);

extern string DecodeFromCharToString(const char* input);

