#include <idc.idc>
#include "lib/lib.idc"

static handle_local_map_leftclick() {
    auto esp = GetRegValue("esp");
    auto x = Dword(esp + 0x04);
    auto y = Dword(esp + 0x08);
    Message("local_map_leftclick(x=%d, y=%d)\n", x, y);
    auto class22 = get_class22();
    Message("%s\n", class22.to_string());
    return 0;
}

static main() {
    Message("\n\n");

    AddBpt(0x0058D250);
    SetBptCnd(0x0058D250, "handle_local_map_leftclick()");

    auto class22 = get_class22();
    Message("%s\n", class22.to_string());
}
