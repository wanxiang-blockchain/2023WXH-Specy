#include <iostream>
#include <common/base64/Transform.h>
#include <spdlog/spdlog.h>

#include "BindingUntrust.h"
using namespace std;

#ifdef __cplusplus
extern "C"
{
#endif

    // for binding debug
    void ocall_print(const char* output_string, size_t string_length) {
        SPDLOG_INFO(output_string);
    }

#ifdef __cplusplus
}
#endif
