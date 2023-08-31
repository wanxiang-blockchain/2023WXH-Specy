# CMakeLists.txt
cmake_minimum_required(VERSION 2.8.9)
project (test_client)

set(BUILD_INTEGRATED ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

include(../cmake/ProtobufGRPC.cmake)

file(GLOB_RECURSE SRCS_PROTOS_UNTRUSTED
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../protos/untrusted/*.cc)

file(GLOB_RECURSE SRCS_COMMON
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../third_party/json_lib/*.cpp)

file(GLOB_RECURSE SRCS_TESTCASES
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    testcases/*.cpp)

find_package(GTest REQUIRED)

# ********** regulator test client start ******************

add_executable(regulator_client regulator_client.cpp basic_server/http_server.cpp ${SRCS_TESTCASES} ${SRCS_PROTOS_UNTRUSTED} ${SRCS_COMMON})

target_link_libraries(regulator_client ${_REFLECTION}
                                  ${_GRPC_GRPCPP}
                                  ${_PROTOBUF_LIBPROTOBUF}
                                  gtest_main
                                  gtest)

add_test(NAME regulator_test COMMAND regulator_client)


# Setup include directories for Main Entrypoint
target_include_directories(regulator_client PRIVATE .
                                               ../
                                               ../third_party/spdlog-1.4.2/include
                                               ../include
                                               ../protos/untrusted)

# ********** regulator test client end ******************

# ********** register test client start ******************

add_executable(register_client register_client.cpp ${SRCS_PROTOS_UNTRUSTED})

target_link_libraries(register_client ${_REFLECTION}
                                  ${_GRPC_GRPCPP}
                                  ${_PROTOBUF_LIBPROTOBUF}
                                  gtest_main
                                  gtest)

add_test(NAME register_test COMMAND register_client)


# Setup include directories for Main Entrypoint
target_include_directories(register_client PRIVATE 
                                            ../third_party/spdlog-1.4.2/include
                                            ../include
                                            ../protos/untrusted
                                            ../)

# ********** register test client end ******************


# add_executable(firehose firehose_server.cpp ${SRCS_PROTOS_UNTRUSTED})

# target_link_libraries(firehose ${_REFLECTION}
#                                   ${_GRPC_GRPCPP}
#                                   ${_PROTOBUF_LIBPROTOBUF})

# target_include_directories(firehose PRIVATE 
#                         ../include
#                         ../common/protos/untrusted_cpp)


