#![allow(non_camel_case_types)]

use std::ffi::CString;
use std::os::raw::c_char;

#[repr(u32)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum AssetsApiBlockMode {
    Null = 0,
    Empty = 1,
}

#[repr(u32)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum AssetsApiSource {
    ResourcePack = 0,
    External = 1,
}

extern "C" {
    pub fn assetsapi_add_folder_resource_pack(
        apk: *const c_char,
        pack: *const c_char,
        recursive: bool,
    ) -> bool;
    pub fn assetsapi_add_folder_external(
        apk: *const c_char,
        pack: *const c_char,
        recursive: bool,
    ) -> bool;
    pub fn assetsapi_set_folder_resource_pack(
        apk: *const c_char,
        pack: *const c_char,
        recursive: bool,
    ) -> bool;
    pub fn assetsapi_set_folder_external(
        apk: *const c_char,
        pack: *const c_char,
        recursive: bool,
    ) -> bool;

    pub fn assetsapi_add_file_resource_pack(
        apk: *const c_char,
        pack: *const c_char,
    ) -> bool;
    pub fn assetsapi_add_file_external(
        apk: *const c_char,
        pack: *const c_char,
    ) -> bool;
    pub fn assetsapi_set_file_resource_pack(
        apk: *const c_char,
        pack: *const c_char,
    ) -> bool;
    pub fn assetsapi_set_file_external(
        apk: *const c_char,
        pack: *const c_char,
    ) -> bool;

    pub fn assetsapi_add_memory_asset(
        apk: *const c_char,
        data: *const u8,
        data_len: usize,
    ) -> bool;
    pub fn assetsapi_set_memory_asset(
        apk: *const c_char,
        data: *const u8,
        data_len: usize,
    ) -> bool;

    pub fn assetsapi_add_block_asset(
        apk: *const c_char,
        recursive: bool,
        mode: u32,
    ) -> bool;
    pub fn assetsapi_set_block_asset(
        apk: *const c_char,
        recursive: bool,
        mode: u32,
    ) -> bool;

    pub fn assetsapi_remove_asset(apk: *const c_char) -> bool;
    pub fn assetsapi_clear_rules();
    pub fn assetsapi_reset_rules();
}

#[inline]
fn with_cstr<F>(s: &str, f: F) -> bool
where
    F: FnOnce(*const c_char) -> bool,
{
    let Ok(s) = CString::new(s) else {
        return false;
    };
    f(s.as_ptr())
}

#[inline]
fn with_two_cstr<F>(a: &str, b: &str, f: F) -> bool
where
    F: FnOnce(*const c_char, *const c_char) -> bool,
{
    let Ok(a) = CString::new(a) else {
        return false;
    };
    let Ok(b) = CString::new(b) else {
        return false;
    };
    f(a.as_ptr(), b.as_ptr())
}

#[inline]
pub fn add_file_resource_pack(apk: &str, pack: &str) -> bool {
    with_two_cstr(apk, pack, |apk, pack| unsafe {
        assetsapi_add_file_resource_pack(apk, pack)
    })
}

#[inline]
pub fn set_file_resource_pack(apk: &str, pack: &str) -> bool {
    with_two_cstr(apk, pack, |apk, pack| unsafe {
        assetsapi_set_file_resource_pack(apk, pack)
    })
}

#[inline]
pub fn set_file_external(apk: &str, pack: &str) -> bool {
    with_two_cstr(apk, pack, |apk, pack| unsafe {
        assetsapi_set_file_external(apk, pack)
    })
}

#[inline]
pub fn set_folder_resource_pack(apk: &str, pack: &str, recursive: bool) -> bool {
    with_two_cstr(apk, pack, |apk, pack| unsafe {
        assetsapi_set_folder_resource_pack(apk, pack, recursive)
    })
}

#[inline]
pub fn set_memory_asset(apk: &str, data: &[u8]) -> bool {
    let Ok(apk) = CString::new(apk) else {
        return false;
    };
    unsafe {
        assetsapi_set_memory_asset(apk.as_ptr(), data.as_ptr(), data.len())
    }
}

#[inline]
pub fn set_block_asset(apk: &str, recursive: bool, mode: AssetsApiBlockMode) -> bool {
    with_cstr(apk, |apk| unsafe {
        assetsapi_set_block_asset(apk, recursive, mode as u32)
    })
}

#[inline]
pub fn remove_asset(apk: &str) -> bool {
    with_cstr(apk, |apk| unsafe {
        assetsapi_remove_asset(apk)
    })
}

#[inline]
pub fn clear_rules() {
    unsafe { assetsapi_clear_rules(); }
}

#[inline]
pub fn reset_rules() {
    unsafe { assetsapi_reset_rules(); }
}

#[inline]
pub fn set_file(
    apk: &str,
    pack: &str,
    source: AssetsApiSource,
) -> bool {
    match source {
        AssetsApiSource::ResourcePack => set_file_resource_pack(apk, pack),
        AssetsApiSource::External => set_file_external(apk, pack),
    }
}
