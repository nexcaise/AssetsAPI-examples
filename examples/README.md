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

