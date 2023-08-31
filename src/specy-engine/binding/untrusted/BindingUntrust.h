#pragma once
#include <iostream>

#ifdef __cplusplus
extern "C"
{
#endif

// for binding debug
void ocall_print(const char* output_string, size_t string_length);

#ifdef __cplusplus
}
#endif