#include "TestUtils.h"


using namespace std;
void bindingInfo(const char* str, const char* file, int line) {
    ocall_print_string(str, file, line);
}

void helper_function (const string& output) {
    uint32_t length = output.length() + 1;
    if (length <= 1) {
        BINDING_INFO("Warning! want to output an empty string");
    }
    char* outputBuffer = (char*)malloc(length);
    memcpy(outputBuffer, output.c_str(), length);
    BINDING_INFO(outputBuffer);
}
