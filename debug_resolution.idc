#include <idc.idc>
#include "lib/lib.idc"

static handle_set_ddraw_resolution() {
    auto esp = GetRegValue("esp");
    auto res_args_ptr = Dword(esp+0x08);
    auto width = Dword(res_args_ptr + 0x08 + 0x00);
    auto height = Dword(res_args_ptr + 0x08 + 0x04);
    Message("### set_ddraw_resolution(%d, %d)\n", width, height);
    return 0;
}

static handle_resolution_after_closing_settings_menu() {
    // Patch in 1920x1080 when closing the settings window
    auto esp = GetRegValue("esp");
    auto old_width = Dword(esp+0x4C);
    auto old_height = Dword(esp+0x50);

    Message("### Overwriting %d x %d\n", old_width, old_height);
    patch_dbg_dword(esp+0x4C, 1920);
    patch_dbg_dword(esp+0x50, 1080);

    return 0;
}

static handle_ddraw_resolution_call_at_loadscreen_end() {
    // Patch in 1920x1080 at the end of the loading screen
    auto esp = GetRegValue("esp");
    auto old_width = Dword(esp+0x3C);
    auto old_height = Dword(esp+0x40);

    Message("### Before scene load overwriting %d x %d\n", old_width, old_height);
    patch_dbg_dword(esp+0x3C, 1920);
    patch_dbg_dword(esp+0x40, 1080);

    return 0;
}

static handle_ddraw_resolution_call_after_first_frame() {
    // Patch in 1920x1080 at the end of the loading screen after the first frame
    auto esp = GetRegValue("esp");
    auto old_width = Dword(esp+0x24);
    auto old_height = Dword(esp+0x28);

    Message("### After scene load overwriting res with %d x %d\n", old_width, old_height);
    patch_dbg_dword(esp+0x24, 1920);
    patch_dbg_dword(esp+0x28, 1080);

    return 0;
}

static handle_resolution_switch_for_ui_corrections() {
    auto new_val = 1280;
    auto old_val = GetRegValue("eax");
    if (old_val <= 1280) {
        Message("### Width %d, not applying ui corrections patch\n", old_val);
        return 0;
    }
    Message("### UI corrections switch sugarcoating width %d with %d\n", old_val, new_val);

    // Set to 1280 width to get a match
    SetRegValue(new_val, "eax");
    Message("### Switch new value %d\n", new_val);

    // Fix anim42 frame0 width (central playing )
    auto anim42 = get_class27().get_anim42_oben_links_1280();
    auto anim42_screen0 = anim42.get_field_a0_entry(0);
    anim42_screen0.set_width(old_val - 284);

    // Fix anim44 pos (bottom right padding)
    auto anim44 = get_class27().get_anim44_rechts_unten_1280();
    Message("### anim44 %s", anim44.to_string());
    anim44.set_pos_x(old_val - 284);

    // old height: 1024, new height: 1080 -> 56 more
    // but the game does not appreciate that
    auto anim44_screen0 = anim44.get_field_a0_entry(0);
    anim44_screen0.set_height(424 + 56);

    return 0;
}

static handle_create_file() {
    auto path_ptr = Dword(GetRegValue("esp")+0x08);
    auto path = GetString(path_ptr, -1, 0);
    Message("Loading %s\n", path);
    if (path == "images\\Vollansichtskarte1280.bmp") {
        return 1;
    }

    return 0;
}

static main() {
    // Print which resolution is being set
    //AddBpt(0x004BCCC0);
    //SetBptCnd(0x004BCCC0, "handle_set_ddraw_resolution()");

    //AddBpt(0x00423C00);
    //SetBptCnd(0x00423C00, "handle_resolution_after_closing_settings_menu()");

    // Set res to fullhd
    //AddBpt(0x00432D58);
    //SetBptCnd(0x00432D58, "handle_ddraw_resolution_call_at_loadscreen_end()");

    // Set res to fullhd
    //AddBpt(0x00463FFD);
    //SetBptCnd(0x00463FFD, "handle_ddraw_resolution_call_after_first_frame()");

    // Fix UI elements and rendering area
    //AddBpt(0x00429AC5);
    //SetBptCnd(0x00429AC5, "handle_resolution_switch_for_ui_corrections()");

    AddBpt(0x006389A0);
    SetBptCnd(0x006389A0, "handle_create_file()");
}
