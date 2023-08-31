cmake_minimum_required(VERSION 3.10)

project(compliance_engine VERSION 0.8)


# Enable SGX SIM runtime
set(SGX_HW OFF)

# Enable Enclave Debug
set(SGX_MODE Debug)

# Only when build a single integrated application
set(BUILD_INTEGRATED ON)

# Do not build Test artifacts
set(BUILD_TEST OFF)

# Use asio standalone mode (instead of relying on boost)
add_definitions(-DASIO_STANDALONE)

# Turn on --use-prefix flag for each integrated Enclaves
add_definitions(-DUSE_ENCLAVE_PREFIX)

# Prepare SGX enabling environment
# Refer to https://github.com/xzhangxa/SGX-CMake
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
find_package(SGX REQUIRED)

# Prepare Protobuf and gRPC enabling environment
include(cmake/ProtobufGRPC.cmake)

# === Enclave EDL files configuration ===
set(KEY_MANAGEMENT_EDL_FILE key_management/trusted/KeyManagementEnclave.edl)
set(RULE_EDL_FILE rule/trusted/RuleEnclave.edl)
set(BINDING_EDL_FILE binding/trusted/BindingEnclave.edl)
set(LOCAL_ATTESTATION_EDL_FILE common/local_attestation/trusted/LocalAttestation.edl)

set(EDL_SEARCH_PATHS common/local_attestation/trusted
                     common/registration/trusted)

# === Configure trusted (Enclave) compilation ===

# Compiles Key Management Module
add_subdirectory(key_management)

# Compiles Rule Check Module
add_subdirectory(rule)

# Compiles Binding Module
add_subdirectory(binding)

# Entrypoint source files
set(M_SRCS main.cpp)


# Common untrusted source files
file(GLOB_RECURSE SRCS_COMMON_UNTRUSTED
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    third_party/json_lib/*.cpp
    common/base64/*.cpp
    common/data_types/binding/*.cpp
    common/local_attestation/untrusted/*.cpp
    common/remote_attestation/*.cpp
    common/utils/untrusted/*.cpp
    )

# Protos untrusted source files
file(GLOB_RECURSE SRCS_PROTOS_UNTRUSTED
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    protos/untrusted/*.cc)

# Request Processor untrusted source files
file(GLOB_RECURSE SRCS_ENGINE
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    engine_server/*.cpp
    )

# Request Processor untrusted source files
file(GLOB_RECURSE SRCS_DATASERVICE
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    dataservice/*.cpp
    )

# Binding untrusted source files
file(GLOB_RECURSE SRCS_BINDING_UNTRUSTED
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    binding/untrusted/*.cpp)

# Rule untrusted source files
file(GLOB_RECURSE SRCS_RULE_UNTRUSTED
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    rule/untrusted/*.cpp)

# Key Management untrusted source files
file(GLOB_RECURSE SRCS_KEY_MANAGEMENT_UNTRUSTED
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    key_management/untrusted/*.cpp)



list(APPEND U_SRCS 
                   ${SRCS_COMMON_UNTRUSTED} 
                   ${SRCS_PROTOS_UNTRUSTED}
                   ${SRCS_ENGINE}
                   ${SRCS_DATASERVICE}
                   ${SRCS_BINDING_UNTRUSTED}
                   ${SRCS_KEY_MANAGEMENT_UNTRUSTED}
                   ${SRCS_RULE_UNTRUSTED})

list(APPEND SRCS ${M_SRCS} ${U_SRCS})

# === Define Target for untrusted (App) compilation ===

# # Main Entrypoint
# add_executable(specy-engine ${SRCS})

add_untrusted_executable(specy-engine USE_PREFIX SRCS ${SRCS}
                        EDL 
                        ${KEY_MANAGEMENT_EDL_FILE} 
                        ${RULE_EDL_FILE} 
                        ${BINDING_EDL_FILE}
                        EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS}
                        )

# Link generated Enclaves into CMAKE_BINARY_DIR after specy-engine is built
add_custom_command(TARGET specy-engine POST_BUILD
                   COMMAND ln -s -f key_management/key_management_enclave.signed.so .
                   COMMAND ln -s -f rule/rule_enclave.signed.so .
                   COMMAND ln -s -f binding/binding_enclave.signed.so .
                   VERBATIM USES_TERMINAL)

# Third-Party libraries needed by Remote Attestation capability
add_subdirectory(third_party/spdlog-1.4.2 ./third_party/spdlog)
add_subdirectory(third_party/cppcodec-0.2 ./third_party/cppcodec)
add_subdirectory(third_party/yaml-cpp-0.7.0 ./third_party/yaml-cpp)

# OpenSSL is required for Remote Attestation capability
find_package(OpenSSL REQUIRED)

# Boost is required for http client
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})


# NOTE: Request Processor is no longer needed as a static lib, instead, we
#       build with specy-engine here in this CMakeLists.txt file
link_directories("common/monitor/build")
target_link_libraries(specy-engine 
                           ${_REFLECTION}
                           ${_GRPC_GRPCPP}
                           ${_PROTOBUF_LIBPROTOBUF}
                           spdlog::spdlog
                           OpenSSL::SSL
                           ${Boost_LIBRARIES}
                           yaml-cpp::yaml-cpp
                           )

# Setup include directories for specy-engine Entrypoint
target_include_directories(specy-engine PRIVATE .
                                third_party/asio-1.12.2/include
                                third_party/spdlog-1.4.2/include
                                third_party/cppcodec-0.2
                                third_party/yaml-cpp-0.7.0/include
                                
                                protos/trusted
                                protos/untrusted
                                include
                                )
