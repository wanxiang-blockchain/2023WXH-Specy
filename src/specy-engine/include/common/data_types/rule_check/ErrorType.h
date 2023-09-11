#pragma once

// TODO fill in a complete list of status code for error handling
enum RuleEnclaveStatus
{
    kOK = 0,
    kError = 1,
    kInvalid_parameter_error = 2,
    kAttestation_error = 3,
    kMalloc_error = 4,
    kRequest_error = 5,
    kEntity_serialize_error = 6,
    kEnclaveid_error = 7,
    kEntity_struct_error = 8,
    kEntity_Query_Generate_error = 9,
    kEntity_Query_Rulefile_error = 10
};