#include "assetsapi.h"
#include <cstdint>
#include <cstdio>
#include <vector>

// Gunakan `xxd -i file > hasil` untuk mengubah suatu file menjadi header di command line atau termux
// use `xxd -i file > result` for change file into header on command line or termux
#include "assets/resources/start_screen.h"
// ------

/*
  Indonesia: Contoh ini menunjukkan cara memakai AssetsAPI dari C++.
  English  : This example shows how to use AssetsAPI from C++.
*/

/*
static void add_rules() {
    // Indonesia: Tambah file dari resource pack.
    // English  : Add a file from the resource pack.
    assetsapi_add_file_resource_pack("gui/some_icon.png", "gui/some_icon.png");

    // Indonesia: Tambah folder dari storage eksternal.
    // English  : Add a folder from external storage.
    assetsapi_add_folder_external("skin_packs/custom/", "games/4dskin/", true);

    // Indonesia: Blokir path tertentu.
    // English  : Block a specific path.
    assetsapi_add_block_asset("definitions/persona/", true, ASSETSAPI_BLOCK_NULL);
}

static void add_memory_asset_example() {
    // Indonesia: Contoh menambah asset dari byte array mentah.
    // English  : Example of adding an asset from a raw byte array.
    static const std::uint8_t kData[] = {
        0x50, 0x4E, 0x47, 0x00, 0x01, 0x02
    };

    assetsapi_add_memory_asset("textures/test.bin", kData, sizeof(kData));
}

static void replace_rules() {
    // Indonesia: Kalau ingin mengganti rule lama, pakai fungsi set_*.
    // English  : If you want to replace an existing rule, use set_*.
    assetsapi_set_file_external("gui/title.png", "my_assets/gui/title.png");
    assetsapi_set_block_asset("resource_packs/persona/", true, ASSETSAPI_BLOCK_EMPTY);
}
*/

__attribute__((constructor))
void mod_init() {
/*
    add_rules();
    add_memory_asset_example();
    replace_rules();

    // Indonesia: Hapus semua rule untuk path tertentu.
    // English  : Remove all rules for a given path.
    assetsapi_remove_asset("gui/title.png");

    // Indonesia: Reset semua rule ke default.
    // English  : Reset all rules back to defaults.
    assetsapi_reset_rules();

    // Indonesia: Bersihkan semua rule yang didaftarkan runtime.
    // English  : Clear all runtime-registered rules.
    assetsapi_clear_rules();
*/
    assetsapi_set_memory_asset(
        "resource_packs/vanilla/ui/start_screen.json",
        start_screen_json,
        start_screen_json_len
    );
    assetsapi_set_block_asset("resource_packs/vanilla/__brarchive/ui.brarchive", true, AssetsApiBlockMode::ASSETSAPI_BLOCK_EMPTY);
}
