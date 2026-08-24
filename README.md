# AssetsAPI Example Repository

This repository demonstrates the intended way to use **AssetsAPI** from
**C++ and Rust** on Android.

The examples follow the same structure used by the project reference:

```text
examples/
├── cpp/
│   ├── CMakeLists.txt
│   ├── dist/libAssetsAPI.so
│   └── src/
│       ├── assetsapi.h
│       ├── example_cpp.cpp
│       └── assets/resources/start_screen.h
└── rust/
    ├── AssetsAPI/libAssetsAPI.so
    ├── Cargo.toml
    ├── build.rs
    └── src/
        ├── assetsapi_ffi.rs
        ├── lib.rs
        └── assets/resources/start_screen.json
```

## Important example

Both C++ and Rust register the bundled `start_screen.json` as:

```text
resource_packs/vanilla/ui/start_screen.json
```

C++ uses the embedded byte array generated from `start_screen.json`.
Rust uses `include_bytes!()` directly.

The public header in `examples/cpp/src/assetsapi.h` is the supplied
`AssetsAPI.h` API header. No replacement wrapper API is introduced.

## C++

The main call is:

```cpp
assetsapi_set_memory_asset(
    "resource_packs/vanilla/ui/start_screen.json",
    start_screen_json,
    start_screen_json_len
);
```

## Rust

The Rust example uses the same exported C ABI:

```rust
let bytes: &[u8] = include_bytes!("assets/resources/start_screen.json");

set_memory_asset(
    "resource_packs/vanilla/ui/start_screen.json",
    bytes,
);
```

## Android build

Build the C++ example with the Android NDK for `arm64-v8a`:

```bash
cmake -S examples/cpp \
  -B examples/cpp/build \
  -DCMAKE_TOOLCHAIN_FILE="$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake" \
  -DANDROID_ABI=arm64-v8a \
  -DANDROID_PLATFORM=android-24 \
  -DCMAKE_BUILD_TYPE=Release

cmake --build examples/cpp/build --config Release
```

For Rust:

```bash
cd examples/rust

cargo build \
  --release \
  --target aarch64-linux-android
```

The Rust target must have the Android linker configured for your NDK.

## Notes

- `libAssetsAPI.so` is supplied as the native dependency.
- This example targets `arm64-v8a`.
- The JSON is kept as a resource file for Rust and also converted into a
  C++ byte array header so the C++ shared library can register it without
  needing to open an external file at runtime.
