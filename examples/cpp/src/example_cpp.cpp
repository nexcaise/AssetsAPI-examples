#include "assetsapi.h"
#include "assets/resources/start_screen.h"

#include <cstdint>
#include <cstdio>

/*
  Indonesia:
  Contoh pemakaian AssetsAPI dari C++. start_screen.json di-embed ke
  binary lalu dipasang sebagai replacement untuk:
  resource_packs/vanilla/ui/start_screen.json.

  English:
  Example of using AssetsAPI from C++. start_screen.json is embedded into
  the binary and registered as a replacement for:
  resource_packs/vanilla/ui/start_screen.json.
*/

__attribute__((constructor))
static void mod_init() {
    const bool ok = assetsapi_set_memory_asset(
        "resource_packs/vanilla/ui/start_screen.json",
        start_screen_json,
        start_screen_json_len
    );

    if (!ok) {
        std::fprintf(stderr, "[AssetsAPI] failed to register start_screen.json\n");
    }
}
