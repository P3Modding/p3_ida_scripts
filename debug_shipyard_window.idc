#include <idc.idc>
#include "lib/lib.idc"

static log_shipyard_window_bp() {
    auto eip = GetRegValue("eip");
    if (eip == 0x5f4326) {
        return 0; // ui_render_shipyard_window
    } else if (eip == 0x005F4229) {
        return 0; // ui_shipyard_window_prepare_page
    } else if (eip == 0x005f47c5) {
        return 0; // ui_shipyard_window_set_new_page
    } else if (eip == 0x005F4172) {
        return 0; // ui_shipyard_window_close
    } else if (eip == 0x5fb16e) {
        return 0; // ui_shipyard_window_read_selected_page_do_stuff 1
    } else if (eip == 0x5fb425) {
        return 0; // ui_shipyard_window_read_selected_page_do_stuff 2
    } else if (eip == 0x5f4093) {
        return 0; // ui_shipyard_window_open
    }

    Message("BP fired at 0x%x\n", eip);
    return 1;
}

static debug_ui_shipyard_window() {
    auto ui_shipyard_window = get_ui_shipyard_window();
    Message("%s\n", ui_shipyard_window.to_string());
}

static main() {
    debug_ui_shipyard_window();
}
