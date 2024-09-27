#include <idc.idc>
#include "lib/lib.idc"

static get_bmp_pointer_from_texture(texture) {
    auto p2 = Dword(texture + 0x2c);
    auto p3 = Dword(p2 + 0x08);
    return p3;
}

static handle_enqueue_class77() {
    refresh_debugger_memory();
    auto eax = GetRegValue("eax");
    auto class77 = Class77(eax);

    Message("Enqueueing %s\n", class77.to_string());

    if (!class77.is_initialized()) {
        Message("unexpected vtable 0x%x\n", class77.get_vtable());
        return 1;
    }

    if (class77.get_texture_id() == 30024) {
        Message("Loading %d", class77.get_texture_id());
        return 1;
    }

    return 0;
}

static main() {
    AddBpt(0x004B3B05);
    SetBptCnd(0x004B3B05, "handle_enqueue_class77()");

    auto class75 = get_class75();
    auto len = class75.get_len();
    
    if (len == 4294967295) {
        return;
    }
    
    Message("Debugging %s\n", class75.to_string());
    auto texture_ids_array = class75.get_texture_ids_array();
    auto i = 0;

    while (i < len) {
        auto texture_id = Dword(texture_ids_array + i * 4);
        if (texture_id == 30024) {
            Message("found Vollansichtskarte1280.bmp at %d\n", i);
            auto class77 = class75.get_class77_by_index(i);
            Message("%s\n", class77.to_string());
            auto bmp_ptr = get_bmp_pointer_from_texture(class77.get_texture_ptr());
            Message("0x%x\n", bmp_ptr);
        }

        i = i+1;
    }

}
