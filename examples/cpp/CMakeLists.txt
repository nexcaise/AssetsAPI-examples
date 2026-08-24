cmake_minimum_required(VERSION 3.22.1)
project(example_assetsapi LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT ANDROID)
    message(FATAL_ERROR "This example is intended to be built with the Android NDK.")
endif()

if(NOT CMAKE_ANDROID_ARCH_ABI STREQUAL "arm64-v8a")
    message(FATAL_ERROR "Unsupported ABI: ${CMAKE_ANDROID_ARCH_ABI}. Only arm64-v8a is supported.")
endif()

add_library(example_assetsapi SHARED
    src/example_cpp.cpp
)

target_include_directories(example_assetsapi PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(example_assetsapi PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)

target_compile_options(example_assetsapi PRIVATE
    -O2
    -ffunction-sections
    -fdata-sections
    -fvisibility=hidden
    -fno-exceptions
    -fno-rtti
)

set(ASSETSAPI_LIB "${CMAKE_CURRENT_SOURCE_DIR}/dist/libAssetsAPI.so")

if(NOT EXISTS "${ASSETSAPI_LIB}")
    message(FATAL_ERROR "Missing ${ASSETSAPI_LIB}")
endif()

find_library(log-lib log REQUIRED)
find_library(android-lib android REQUIRED)

target_link_libraries(example_assetsapi PRIVATE
    "${ASSETSAPI_LIB}"
    ${log-lib}
    ${android-lib}
    dl
)

target_link_options(example_assetsapi PRIVATE
    -Wl,--gc-sections
    -Wl,--strip-all
)
