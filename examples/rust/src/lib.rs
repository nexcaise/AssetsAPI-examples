mod assetsapi_ffi;

use assetsapi_ffi::{
    set_file_resource_pack,
    set_folder_resource_pack,
    set_memory_asset,
    set_block_asset,
    AssetsApiBlockMode,
};

/// Example usage of AssetsAPI from Rust.
#[ctor::ctor]
fn main() {
    // Replace the vanilla start screen with the bundled JSON.
    let bytes: &[u8] = include_bytes!("assets/resources/start_screen.json");
    let ok = set_memory_asset(
        "resource_packs/vanilla/ui/start_screen.json",
        bytes,
    );
    println!("set_memory_asset(start_screen.json) = {ok}");

    // Example: map a folder from a resource pack.
    let ok = set_folder_resource_pack("renderer", "renderdragon", true);
    println!("set_folder_resource_pack = {ok}");

    // Example: block the archived UI resource.
    let ok = set_block_asset(
        "resource_packs/vanilla/__brarchive/ui.brarchive",
        true,
        AssetsApiBlockMode::Empty,
    );
    println!("set_block_asset = {ok}");

    // Example: direct resource-pack file replacement.
    // let ok = set_file_resource_pack("gui/title.png", "gui/title.png");
    // println!("set_file_resource_pack = {ok}");
}
