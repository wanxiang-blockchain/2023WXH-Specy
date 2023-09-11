#include "BindingEnclave_t.h"
#include <iostream>
#include <string>

#define BINDING_INFO(str) bindingInfo(str, __FILE__, __LINE__)
void bindingInfo(const char* str, const char* file, int line);

void helper_function (const std::string& output);
#define BINDING_INFO_STRING(str) BINDING_INFO(str.c_str())

