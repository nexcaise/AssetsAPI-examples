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

__attribute__((constructor))
void mod_init() {
    assetsapi_set_memory_asset(
        "resource_packs/vanilla/ui/start_screen.json",
        start_screen_json,
        start_screen_json_len
    );
    assetsapi_set_block_asset("resource_packs/vanilla/__brarchive/ui.brarchive", true, 1);
}
