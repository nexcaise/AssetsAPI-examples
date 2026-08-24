fn main() {
    println!("cargo:rustc-link-search=native={}", "AssetsAPI");
    println!("cargo:rustc-link-lib=AssetsAPI");
    println!("cargo:rerun-if-changed=src");
}