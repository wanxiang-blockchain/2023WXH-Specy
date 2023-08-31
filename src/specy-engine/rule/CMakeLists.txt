cmake_minimum_required(VERSION 3.10)

project(rule_checker VERSION 0.8)

# Enable SGX SIM runtime
set(SGX_HW OFF)

# Enable Enclave Debug
set(SGX_MODE Debug)

# Only build sub-module Enclaves
set(BUILD_INTEGRATED ON)

# Do not build Test artifacts
# set(BUILD_TEST OFF)

# Indicate we are buiding rule check module now (which employs local attestation code)
add_definitions(-DBUILD_RULE_CHECK_MODULE)

# add_definitions(-DHAVE_OPENSSL)

# Indicate to compile this module with protocol buffer header version 3.7
add_definitions(-DBUILD_WITH_PROTOCOL_BUFFER_3_7)

# Define to use latest local attestation library
# add_definitions(-DUSE_LATEST_LOCAL_ATTESTATION_LIB)

# Define to turn on Debug mode for Rule Check Module
if (NOT BUILD_INTEGRATED)
    add_definitions(-DDEBUG_RULE_CHECK_MODULE)
endif()

# Prepare SGX enabling environment
# Refer to https://github.com/xzhangxa/SGX-CMake
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../cmake)
find_package(SGX REQUIRED)
find_package(OpenSSL REQUIRED)

# Use C++ 11 in Enclave
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Now, start Enclave (trusted code) configurations

# Set .edl file and search path
set(EDL_FILE trusted/RuleEnclave.edl)
# For local attestation trusted lib compilation
set(EDL_FILE_LOCAL_ATTESTATION ../common/local_attestation/trusted/LocalAttestation.edl)
set(EDL_SEARCH_PATHS trusted ../common/local_attestation/trusted)

# Set Enclave signing private key
set(ENCLAVE_SIGN_KEY trusted/RuleEnclave_private.pem)

# Set Enclave configuration .xml file
set(ENCLAVE_CONF_FILE trusted/RuleEnclave.config.xml)

# Prepare Enclave source code files
# set(E_SRCS trusted/Enclave.cpp)
file(GLOB_RECURSE E_SRCS_RULE_CHECK
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    trusted/*.cpp)
# remove test files if build integrated application
if (BUILD_INTEGRATED)
    list(FILTER E_SRCS_RULE_CHECK EXCLUDE REGEX .*/test/.*)
endif()
list(APPEND E_SRCS ${E_SRCS_RULE_CHECK})

# Prepare Enclave source code files
# set(T_SRCS Enclave/TrustedLibrary/Libcxx.cpp)
file(GLOB_RECURSE T_SRCS_ANTLR4_RUNTIME
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../third_party/antlr4_runtime_trusted/*.cpp)

file(GLOB_RECURSE T_SRCS_DATA_TYPES
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../common/data_types/*.cpp)

file(GLOB_RECURSE T_SRCS_JSON_LIB
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../third_party/json_lib/json11.cpp)

# base64 lib source files
file(GLOB_RECURSE T_SRCS_BASE64
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../common/base64/*.cpp)

# protobuf lib source files
file(GLOB_RECURSE T_SRCS_PROTOBUF_LIB
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../third_party/protobuf/trusted_protobuf_src/*.cc)

# remove test files from protobuf lib source code files
list(FILTER T_SRCS_PROTOBUF_LIB EXCLUDE REGEX .*test.*)
list(FILTER T_SRCS_PROTOBUF_LIB EXCLUDE REGEX .*/testing/.*)

# remove compiler files from protobuf lib source code files
list(FILTER T_SRCS_PROTOBUF_LIB EXCLUDE REGEX .*/compiler/.*)

# remove util files from protobuf lib source code files
list(FILTER T_SRCS_PROTOBUF_LIB EXCLUDE REGEX .*/util/.*)

file(GLOB_RECURSE T_SRCS_PROTOS
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../protos/trusted/e2e_message/*.cc
    ../protos/trusted/rule_enclave/*.cc)

list(APPEND T_SRCS ${T_SRCS_ANTLR4_RUNTIME} ${T_SRCS_DATA_TYPES}
                   ${T_SRCS_JSON_LIB} ${T_SRCS_BASE64}
                   ${T_SRCS_PROTOBUF_LIB} ${T_SRCS_PROTOS})

# local attestation lib source files
file(GLOB_RECURSE T_SRCS_LOCAL_ATTESTATION_LIB
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../common/local_attestation/trusted/*.cpp)

# Select on appropriate .lds file
if(SGX_HW AND SGX_MODE STREQUAL "Release")
    set(LDS trusted/RuleEnclave.lds)
else()
    set(LDS trusted/RuleEnclave_debug.lds)
endif()

# Prepare Enclave and trusted libraries
# Refer to https://github.com/xzhangxa/SGX-CMake
add_trusted_library(rule_enclave_trusted_lib SRCS ${T_SRCS} EDL ${EDL_FILE}
                    EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS})

add_trusted_library(rule_enclave_local_attestation_trusted_lib SRCS ${T_SRCS_LOCAL_ATTESTATION_LIB}
                    EDL ${EDL_FILE} EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS})

if (NOT BUILD_INTEGRATED)
    add_enclave_library(rule_enclave SRCS ${E_SRCS}
                        TRUSTED_LIBS rule_enclave_trusted_lib rule_enclave_local_attestation_trusted_lib
                        EDL ${EDL_FILE} EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS}
                        LDSCRIPT ${LDS})
else()
    add_enclave_library(rule_enclave USE_PREFIX SRCS ${E_SRCS}
                        TRUSTED_LIBS rule_enclave_trusted_lib rule_enclave_local_attestation_trusted_lib
                        EDL ${EDL_FILE} EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS}
                        LDSCRIPT ${LDS})
endif()

target_link_libraries(rule_enclave
                    /opt/intel/sgxssl/lib64/libsgx_tsgxssl.a 
                    /opt/intel/sgxssl/lib64/libsgx_tsgxssl_crypto.a
                    /opt/intel/sgxssl/lib64/libsgx_usgxssl.a)

# Path for finding local attestation header files (needed in SGX proxy/bridge compilation)
include_directories(.
                    /opt/intel/sgxssl/include
                    ../third_party/antlr4_runtime_trusted
                    ../third_party/protobuf/trusted_protobuf_src
                    ../third_party/merklecpp
                    ../protos/trusted
                    ../include
                    ../)

target_include_directories(rule_enclave PRIVATE
                        ${SGX_INCLUDE_DIR}
                        )

# Set Enclave signing configuration
enclave_sign(rule_enclave KEY ${ENCLAVE_SIGN_KEY} CONFIG ${ENCLAVE_CONF_FILE})

# Now, start App (untrusted part code) configurations

# Omit untrusted App if instructed to build only enclave
if(NOT BUILD_INTEGRATED)
    # Prepare App source code files
    # set(SRCS untrusted/TestRuleApp.cpp)

    # Prepare App executable
    # Refer to https://github.com/xzhangxa/SGX-CMake
    add_untrusted_executable(rule_checker SRCS ${SRCS} EDL ${EDL_FILE}
                        EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS})

    # Prepare App header files
    target_include_directories(rule_checker PRIVATE untrusted ../include)

    # Claim rule_checker to be built after rule_enclave-sign
    add_dependencies(rule_checker rule_enclave-sign)
endif()
