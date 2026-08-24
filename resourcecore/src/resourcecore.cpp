#include "assetsapi.h"

__attribute__((constructor))
static void mod_init() {
    assetsapi_set_folder_resource_pack("renderer/","renderer/", true);
    assetsapi_set_folder_resource_pack("gui/","gui/", true);
    assetsapi_set_folder_resource_pack("resource_packs/vanilla/cameras/","vanilla_cameras/", true);
    assetsapi_set_folder_resource_pack("skin_packs/","skin_packs/", true);
}
