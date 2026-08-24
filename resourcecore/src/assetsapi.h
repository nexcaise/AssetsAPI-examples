#pragma once

#include <cstddef>
#include <cstdint>

#if defined(__ANDROID__)
#include <sys/types.h>
#else
#include <cstdint>
using off_t = std::int64_t;
using off64_t = std::int64_t;
#endif

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__GNUC__) || defined(__clang__)
#define ASSETSAPI_EXPORT __attribute__((visibility("default")))
#else
#define ASSETSAPI_EXPORT
#endif

// Replacement source: 0 = resource pack, 1 = /storage/emulated/0.
ASSETSAPI_EXPORT bool assetsapi_add_folder_resource_pack(const char* apk, const char* pack, bool recursive);
ASSETSAPI_EXPORT bool assetsapi_add_folder_external(const char* apk, const char* pack, bool recursive);
ASSETSAPI_EXPORT bool assetsapi_set_folder_resource_pack(const char* apk, const char* pack, bool recursive);
ASSETSAPI_EXPORT bool assetsapi_set_folder_external(const char* apk, const char* pack, bool recursive);

ASSETSAPI_EXPORT bool assetsapi_add_file_resource_pack(const char* apk, const char* pack);
ASSETSAPI_EXPORT bool assetsapi_add_file_external(const char* apk, const char* pack);
ASSETSAPI_EXPORT bool assetsapi_set_file_resource_pack(const char* apk, const char* pack);
ASSETSAPI_EXPORT bool assetsapi_set_file_external(const char* apk, const char* pack);

ASSETSAPI_EXPORT bool assetsapi_add_memory_asset(const char* apk, const std::uint8_t* data, std::size_t data_len);
ASSETSAPI_EXPORT bool assetsapi_set_memory_asset(const char* apk, const std::uint8_t* data, std::size_t data_len);

// mode: 0 = null/block, 1 = empty asset.
ASSETSAPI_EXPORT bool assetsapi_add_block_asset(const char* apk, bool recursive, std::uint32_t mode);
ASSETSAPI_EXPORT bool assetsapi_set_block_asset(const char* apk, bool recursive, std::uint32_t mode);

ASSETSAPI_EXPORT bool assetsapi_remove_asset(const char* apk);
ASSETSAPI_EXPORT void assetsapi_clear_rules();
ASSETSAPI_EXPORT void assetsapi_reset_rules();

#if defined(__cplusplus)
}
#endif

#undef ASSETSAPI_EXPORT
