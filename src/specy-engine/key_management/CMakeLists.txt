cmake_minimum_required(VERSION 3.10)
project(key_management)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SGX_SSL_PATH /opt/intel/sgxssl)

# Enable SGX SIM runtime
set(SGX_HW OFF)

# Enable Enclave Debug
set(SGX_MODE Debug)

# Only build sub-module Enclaves
set(BUILD_INTEGRATED ON)

# Do not build Test artifacts
set(BUILD_TEST OFF)

# Indicate we are buiding key management module now (which employs local attestation code)
add_definitions(-DBUILD_KEY_MANAGEMENT_MODULE)

# Prepare SGX enabling environment
# Refer to https://github.com/xzhangxa/SGX-CMake
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../cmake)
find_package(SGX REQUIRED)

# Use asio standalone mode (instead of relying on boost)
add_definitions(-DASIO_STANDALONE)

# Now, start Enclave (trusted code) configurations
include_directories(${SGX_INCLUDE_DIR} 
                    ../common/local_attestation/include
                    ../key_management/trusted
                    ..
                    test/Enclave2
                    test/Enclave3
                    test

                    ../protos/trusted/e2e_message
                    ../common/base64
                    ../third_party/protobuf/trusted_protobuf_src
                    ../common/crypto/trusted
                    ../common/local_attestation/trusted 
                    ../common/remote_attestation/untrusted
                    ../common/local_attestation/untrusted 
                    ../common/utils/trusted
                    ../include)


# Set .edl file and search path
##################################For TEST###########################
set(EDL_SEARCH_PATHS
    trusted
    
    test/Enclave2
    test/Enclave3

    ../common/local_attestation/trusted
    ../common/registration/trusted)


#####################################################################
set(EDL_FILE trusted/KeyManagementEnclave.edl)

# Set Enclave signing private key
set(ENCLAVE_SIGN_KEY trusted/KeyManagementEnclave_private.pem)

# Set Enclave configuration .xml file
set(ENCLAVE_CONF_FILE trusted/KeyManagementEnclave.config.xml)

# Prepare Enclave source code files

file(GLOB_RECURSE E_SRCS_KEY_MANAGEMENT
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    trusted/*.cpp)
list(APPEND E_SRCS ${E_SRCS_KEY_MANAGEMENT})

file(GLOB_RECURSE T_MESSAGE_EXCHANGE_SRCS
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../common/local_attestation/trusted/*.cpp)

file(GLOB_RECURSE T_COMMON_UTILS_SRCS
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../common/utils/trusted/*.cpp
    ../common/base64/*.cpp
    ../common/crypto/trusted/*.cpp)

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
    )

list(APPEND T_SRCS ${T_MESSAGE_EXCHANGE_SRCS} 
                   ${T_COMMON_UTILS_SRCS}
                   ${T_SRCS_PROTOBUF_LIB}
                   ${T_SRCS_PROTOS})


# Select on appropriate .lds file
if(SGX_HW AND SGX_MODE STREQUAL "Release")
    set(LDS trusted/KeyManagementEnclave.lds)
else()
    set(LDS trusted/KeyManagementEnclave_debug.lds)
endif()

add_trusted_library(key_management_trusted_lib SRCS ${T_SRCS} 
                    EDL ${EDL_FILE}
                    EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS})

if (NOT BUILD_INTEGRATED)
    add_enclave_library(key_management_enclave
                        SRCS ${E_SRCS}
                        TRUSTED_LIBS key_management_trusted_lib
                        EDL ${EDL_FILE}
                        EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS}
                        USE_PREFIX
                        LDSCRIPT ${LDS})
else()
    add_enclave_library(key_management_enclave USE_PREFIX
                        SRCS ${E_SRCS}
                        TRUSTED_LIBS key_management_trusted_lib
                        EDL ${EDL_FILE}
                        EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS}
                        USE_PREFIX
                        LDSCRIPT ${LDS})
endif()

###########################################################
# Build Enclave 2 and Enclave 3 only when explicitly directed
if(BUILD_TEST)
    add_enclave_library(Enclave2
                        SRCS test/Enclave2/Enclave2.cpp test/Enclave2/Utility_E2.cpp
                        TRUSTED_LIBS key_management_trusted_lib
                        EDL test/Enclave2/Enclave2.edl
                        EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS}
                        USE_PREFIX
                        LDSCRIPT test/Enclave2/Enclave2.lds)

    add_enclave_library(Enclave3
                        SRCS test/Enclave3/Enclave3.cpp test/Enclave3/Utility_E3.cpp
                        TRUSTED_LIBS key_management_trusted_lib
                        EDL test/Enclave3/Enclave3.edl
                        EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS}
                        USE_PREFIX
                        LDSCRIPT test/Enclave3/Enclave3.lds)
endif()

################################################################################

# Link Enclave with SGX SSL library
target_link_libraries(key_management_enclave
                    /opt/intel/sgxssl/lib64/libsgx_tsgxssl.a 
                    /opt/intel/sgxssl/lib64/libsgx_tsgxssl_crypto.a
                    /opt/intel/sgxssl/lib64/libsgx_usgxssl.a)
# boost_system pthread z m rt atomic ssl crypto dl

target_link_directories(key_management_enclave PRIVATE ${SGX_SSL_PATH}/lib64)
                    

# Prepare Enclave and trusted header files
target_include_directories(key_management_trusted_lib PRIVATE
                        ../include
                        ../common/protobuf/trusted_protobuf_src
                        ../protos/trusted_cpp/e2e_message)

# Set Enclave signing configuration
enclave_sign(key_management_enclave KEY ${ENCLAVE_SIGN_KEY} CONFIG ${ENCLAVE_CONF_FILE})

###########################################################
# Build Enclave 2 and Enclave 3 only when explicitly directed
if(BUILD_TEST)
    enclave_sign(Enclave2 OUTPUT libenclave2.so
                KEY test/Enclave2/Enclave2_private.pem
                CONFIG test/Enclave2/Enclave2.config.xml)

    enclave_sign(Enclave3 OUTPUT libenclave3.so
                KEY test/Enclave3/Enclave3_private.pem
                CONFIG test/Enclave3/Enclave3.config.xml)
endif()
###########################################################


# Now, start App (untrusted part code) configurations
###########################################################

# Omit untrusted App if instructed to build only enclave
if(NOT BUILD_INTEGRATED)
    file(GLOB_RECURSE U_SRCS_APP
        LIST_DIRECTORIES false 
        CONFIGURE_DEPENDS
        test/App.cpp)

    ############################################################

    # Prepare App source code files

    file(GLOB_RECURSE U_SRCS_KEY_MANAGEMENT
        LIST_DIRECTORIES false 
        CONFIGURE_DEPENDS
        untrusted/*.cpp)

    file(GLOB_RECURSE U_LOCAL_ATTESTATION
        LIST_DIRECTORIES false 
        CONFIGURE_DEPENDS
        ../common/local_attestation/untrusted/*.cpp)

    file(GLOB_RECURSE U_REMOTE_ATTESTATION
        LIST_DIRECTORIES false 
        CONFIGURE_DEPENDS
        ../common/remote_attestation/untrusted/*.cpp)

    file(GLOB_RECURSE U_COMMON_UTILS
        LIST_DIRECTORIES false 
        CONFIGURE_DEPENDS
        ../common/utils/untrusted/*.cpp)

    list(APPEND U_SRCS 
                ${U_SRCS_APP} 
                ${U_SRCS_KEY_MANAGEMENT} 
                ${U_LOCAL_ATTESTATION} 
                ${U_REMOTE_ATTESTATION} 
                ${U_COMMON_UTILS})


    # Prepare App executable
    # Refer to https://github.com/xzhangxa/SGX-CMake
    add_untrusted_executable(key_management 
                            SRCS ${U_SRCS}
                            USE_PREFIX 
                            EDL ${EDL_FILE} test/Enclave2/Enclave2.edl test/Enclave3/Enclave3.edl
                            EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS})

    target_include_directories(key_management PRIVATE 
                                untrusted
                                ../include
                                )


    ##### third_pary #####
    add_subdirectory(../common/utils/third_party/spdlog-1.4.2 ./third_party/spdlog)
    add_subdirectory(../common/utils/third_party/cppcodec-0.2 ./third_party/cppcodec)
    add_subdirectory(../common/utils/third_party/json11 ./third_party/json11)

    find_package(OpenSSL REQUIRED)

    target_link_libraries(key_management PRIVATE spdlog::spdlog OpenSSL::SSL json11)


    target_include_directories(key_management PRIVATE
                                ../include
                                untrusted 
                                untrusted/verifier
                                ../common/utils/untrusted
                                ../common/remote_attestation/untrusted
                                ../common/utils/third_party/cppcodec-0.2
                                ../common/utils/third_party/json11
                                ../common/utils/third_party/asio-1.12.2/include
                                ../common/utils/third_party/spdlog-1.4.2/include)

    # Claim rule_checker to be built after enclave-sign
    add_dependencies(key_management KeyManagementEnclave-sign Enclave2-sign Enclave3-sign)
endif()