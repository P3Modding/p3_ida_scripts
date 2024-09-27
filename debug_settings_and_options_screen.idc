#include <idc.idc>
#include "lib/lib.idc"

static handle_ui_render_settings_screen_selection() {
    eax = GetRegValue("eax");
    if (eax != 0x12) {
        Message("Game settings button 0x%x has been pressed\n", eax);
    }

    return 0;
}

static handle_ui_render_options_screen_selection() {
    edi = GetRegValue("edi");
    if (edi != 0x14) {
        Message("Game options button 0x%x has been pressed\n", edi);
    }

    return 0;
}

static main() {
    auto bp1 = AddBpt(0x004987D8);
    SetBptCnd(0x004987D8, "handle_ui_render_settings_screen_selection()");

    auto bp2 = AddBpt(0x0045F28E);
    SetBptCnd(0x0045F28E, "handle_ui_render_options_screen_selection()");

    Message("options screen=0x%x settings screen=0x%x\n", options_screen, settings_screen);
}
