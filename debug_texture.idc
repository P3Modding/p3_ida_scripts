#include <idc.idc>
#include "lib/lib.idc"

static handle_get_texture_by_id() {
    auto texture_id = Dword(GetRegValue("esp") + 0x04);
    if (texture_id == 30024) {
        return 1; // Vollansichtskarte1280.bmp
    }

    Message("Getting texture %d\n", texture_id);
}

static main() {
    AddBpt(0x004B3DD0);
    SetBptCnd(0x004B3DD0, "handle_get_texture_by_id()");
}
