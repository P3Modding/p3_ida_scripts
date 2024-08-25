#include <idc.idc>
#include "lib/lib.idc"

static handle_j_ddraw_dll_sgl_DrawLine() {
    auto esp = GetRegValue("esp");
    auto y2 = get_fpnum(esp + 0x10, 4);
    auto x2 = get_fpnum(esp + 0x0c, 4);
    auto y1 = get_fpnum(esp + 0x08, 4);
    auto x1 = get_fpnum(esp + 0x04, 4);
    Message("x1=%05f y1=%05f x2=%05f y2=%05f\n", x1, y1, x2, y2);
}

static handle_render_thing2() {
    j_ddraw_dll_sgl_SetConstantColor_ptr(0xffffffff);
    //j_ddraw_dll_sgl_FillSolidRect_ptr(1, 1, 250, 250);
    //j_ddraw_dll_sgl_SetBlendMode_ptr(3);

    //j_ddraw_dll_sgl_DrawLine(0x3f800000, 0x3f800000, 0x43fa0000, 0x43fa0000);
    //raw_geometry(1, 1, 500, 500);
    //SetRegValue(GetRegValue("eax") + 100, "eax");
    SetRegValue(1, "eax");
    SetRegValue(1, "ebx");
    SetRegValue(500, "edi");
    SetRegValue(500, "esi");
    
    //auto lines_count = Dword(0x006CBDDC);
    //lines_count = lines_count + 1;
    //patch_dbg_dword(0x006CBDDC, lines_count);

    return 0;
}

static main() {
    auto bp1 = AddBpt(0x004BB390);
    SetBptCnd(0x004BB390, "handle_j_ddraw_dll_sgl_DrawLine()");

    auto bp3 = AddBpt(0x0044B518);
    SetBptCnd(0x0044B518, "handle_render_thing2()");
}
