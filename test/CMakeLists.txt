##########################################################################

cmake_minimum_required(VERSION 2.8)

##########################################################################

project(test-ArduinoCore-API)

##########################################################################

include_directories(../api)
include_directories(external/catch/v2.13.1/include)

##########################################################################

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

##########################################################################

set(TEST_TARGET ${CMAKE_PROJECT_NAME})

##########################################################################

set(TEST_SRCS
  src/Common/test_max.cpp
  src/WCharacter/test_isHexadecimalDigit.cpp
  src/WCharacter/test_isSpace.cpp
  src/WCharacter/test_isUpperCase.cpp
)

set(TEST_DUT_SRCS
  ../api/Common.cpp
)

##########################################################################

set(TEST_TARGET_SRCS
  src/main.cpp
  ${TEST_SRCS}
  ${TEST_UTIL_SRCS}
  ${TEST_DUT_SRCS}
)

##########################################################################

add_compile_definitions(HOST)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)
add_compile_options(-Wno-cast-function-type)

set(CMAKE_C_FLAGS   ${CMAKE_C_FLAGS}   "--coverage")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "--coverage -Wno-deprecated-copy")

##########################################################################

add_executable(
  ${TEST_TARGET}
  ${TEST_TARGET_SRCS}
)

##########################################################################

