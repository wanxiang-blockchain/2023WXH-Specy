cmake_minimum_required(VERSION 3.10)

project(binding VERSION 0.8)

# Enable SGX SIM runtime
set(SGX_HW OFF)

# Enable Enclave Debug
set(SGX_MODE Debug)

# Only build sub-module Enclaves
set(BUILD_INTEGRATED ON)

# Do not build Test artifacts
set(BUILD_TEST OFF)

# Indicate we are buiding binding module now (which employs local attestation code)
add_definitions(-DBUILD_BINDING_MODULE)

# Indicate to compile this module with protocol buffer header version 3.7
add_definitions(-DBUILD_WITH_PROTOCOL_BUFFER_3_7)

# Prepare SGX enabling environment
# Refer to https://github.com/xzhangxa/SGX-CMake
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../cmake)
find_package(SGX REQUIRED)

# Use C++ 11 in Enclave
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Now, start Enclave (trusted code) configurations

# Set .edl file and search path
set(EDL_FILE trusted/BindingEnclave.edl)
# For local attestation trusted lib compilation
set(EDL_FILE_LOCAL_ATTESTATION ../common/local_attestation/trusted/LocalAttestation.edl)
set(EDL_SEARCH_PATHS trusted ../common/local_attestation/trusted ../common/monitor/trusted)

# Set Enclave signing private key
set(ENCLAVE_SIGN_KEY trusted/BindingEnclave_private.pem)

# Set Enclave configuration .xml file
set(ENCLAVE_CONF_FILE trusted/BindingEnclave.config.xml)

# Prepare Enclave source code files
# set(E_SRCS trusted/Enclave.cpp)
file(GLOB_RECURSE E_SRCS_BINDING
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    trusted/*.cpp)
# Exclude main.cpp from trusted source files
list(FILTER E_SRCS_BINDING EXCLUDE REGEX main.cpp)
# Exclude mocks/* from trusted source files
# list(FILTER E_SRCS_BINDING EXCLUDE REGEX .*mocks.*)

list(APPEND E_SRCS ${E_SRCS_BINDING})

# Prepare Enclave source code files
# set(T_SRCS Enclave/TrustedLibrary/Libcxx.cpp)
file(GLOB_RECURSE T_SRCS_ANTLR4_RUNTIME
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDSantlr4_runtime
    ../third_party/antlr4_runtime_trusted/*.cpp)

file(GLOB_RECURSE T_SRCS_JSON_LIB
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../common/json_lib/json11.cpp)

file(GLOB_RECURSE T_SRCS_BASE64_LIB
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
    ../protos/trusted/binding_enclave/*.cc
    ../protos/trusted/e2e_message/*.cc)


list(APPEND T_SRCS ${T_SRCS_ANTLR4_RUNTIME} 
                   ${T_SRCS_JSON_LIB}
                   ${T_SRCS_BASE64_LIB} ${T_SRCS_PROTOBUF_LIB}
                   ${T_SRCS_PROTOS})

# local attestation lib source files
file(GLOB_RECURSE T_SRCS_LOCAL_ATTESTATION_LIB
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../common/local_attestation/trusted/*.cpp)

# Select on appropriate .lds file
if(SGX_HW AND SGX_MODE STREQUAL "Release")
    set(LDS trusted/BindingEnclave.lds)
else()
    set(LDS trusted/BindingEnclave_debug.lds)
endif()

# Prepare Enclave and trusted libraries
# Refer to https://github.com/xzhangxa/SGX-CMake
add_trusted_library(binding_enclave_trusted_lib SRCS ${T_SRCS} EDL ${EDL_FILE}
                    EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS})

add_trusted_library(binding_enclave_local_attestation_trusted_lib SRCS ${T_SRCS_LOCAL_ATTESTATION_LIB}
                    EDL ${EDL_FILE} EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS})

if (NOT BUILD_INTEGRATED)
    add_enclave_library(binding_enclave SRCS ${E_SRCS}
                        TRUSTED_LIBS binding_enclave_trusted_lib binding_enclave_local_attestation_trusted_lib
                        EDL ${EDL_FILE} EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS}
                    LDSCRIPT ${LDS})
else()
    add_enclave_library(binding_enclave USE_PREFIX SRCS ${E_SRCS}
                        TRUSTED_LIBS binding_enclave_trusted_lib binding_enclave_local_attestation_trusted_lib
                        EDL ${EDL_FILE} EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS}
                        LDSCRIPT ${LDS})
endif()

# Path for finding local attestation header files (needed in SGX proxy/bridge compilation)
include_directories(.
                    ../third_party/antlr4_runtime_trusted
                    ../third_party/protobuf/trusted_protobuf_src
                    ../protos/trusted
                    ../include)


target_include_directories(binding_enclave PRIVATE 
                        ${SGX_INCLUDE_DIR}
                        )


# Set Enclave signing configuration
enclave_sign(binding_enclave KEY ${ENCLAVE_SIGN_KEY} CONFIG ${ENCLAVE_CONF_FILE})

# Now, start App (untrusted part code) configurations

# Omit untrusted App if instructed to build only enclave
if(NOT BUILD_INTEGRATED)
    # Prepare App source code files
    file(GLOB_RECURSE U_SRCS_BASE64_LIB
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../common/base64/*.cpp)

    file(GLOB_RECURSE U_SRCS_LOCAL_ATTESTATION_LIB
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../common/local_attestation/untrusted/*.cpp)

    file(GLOB_RECURSE U_SRCS_PROTOBUF
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../protos/trusted_cpp/binding_enclave/*.cc
    ../protos/trusted_cpp/e2e_message/*.cc)

    file(GLOB_RECURSE U_SRCS_BINDING_UNTRUSTED
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    untrusted/*.cpp)

    add_subdirectory(../common/utils/third_party/spdlog-1.4.2 ./third_party/spdlog)


    # set(SRCS main.cpp untrusted/BindingQuery.cpp untrusted/BindingUntrust.cpp)
    list(APPEND U_SRCS main.cpp 
                       ${U_SRCS_BASE64_LIB}
                       ${U_SRCS_LOCAL_ATTESTATION_LIB}
                       ${U_SRCS_PROTOBUF}
                       ${U_SRCS_BINDING_UNTRUSTED})

    # Prepare App executable
    # Refer to https://github.com/xzhangxa/SGX-CMake
    add_untrusted_executable(binding SRCS ${U_SRCS} EDL ${EDL_FILE}
                        EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS})

    # Prepare App header files
    target_include_directories(binding PRIVATE .
                              ../common/protobuf/untrusted_protobuf_include
                              ../common/protos/trusted_cpp
                              ../common/third_party/spdlog-1.4.2/include
                              )

    # Untrusted App can be linked with enclosed protocol buffer static library
    target_link_libraries(binding ../common/protobuf/untrusted_lib/libprotobuf.a spdlog::spdlog)

    # Claim binding to be built after binding_enclave-sign
    add_dependencies(binding binding_enclave-sign)
endif()
