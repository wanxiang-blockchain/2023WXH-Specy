#pragma once

typedef enum KEYMANAGEMENT_ERROR_CODE{
    kKM_SUCCESS = 0,
    kECALL_INIT_ERROR = 1,
    kSEND_PEERTX_ERROR = 2,
    kGET_QUOTE_ERROR = 3,
    kCREATE_REPORT_ERROR = 4,
    kGET_PK_KEY_ERROR = 5
}keymanagement_status_t;