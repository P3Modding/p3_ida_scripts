#include <idc.idc>
#include "lib/lib.idc"

static handle_is_direct_path() {
    Message("\n\n\n");
    auto dst_ptr = GetRegValue("eax");
    auto src_ptr = GetRegValue("ecx");
    Message("(%d, %d) -> (%d, %d)\n",
        Word(src_ptr + 0x00),
        Word(src_ptr + 0x02),
        Word(dst_ptr + 0x00),
        Word(dst_ptr + 0x02)
    );
}

static handle_is_direct_path_cell_check_loop() {
    auto esp = GetRegValue("esp");
    auto dx_increment = TO_LONG(Dword(esp + 0x14 + 0x10));
    auto dy_increment = TO_LONG(GetRegValue("ebx"));

    auto check_type = "";
    auto ebp = GetRegValue("ebp");
    auto eax = GetRegValue("eax");
    if (ebp >= eax) {
        check_type = "east-west";
    } else {
        check_type = "north-south";
    }

    //Message("dx_increment = %d, dy_increment=%d, check_type=%s\n", dx_increment, dy_increment, check_type);
    return 0;
}

static handle_assert_water_cell_1() {
    auto esp = GetRegValue("esp");
    auto base = Dword(esp + 0x14 + 0x04);
    auto width = Dword(Dword(esp + 0x14 + 0x08));
    auto ecx = GetRegValue("ecx");
    auto bytes_offset = ecx - base;
    auto x = bytes_offset % width;
    auto y = bytes_offset / width;
    Message("Checking cell (east-west 1) (%d, %d)\n", x, y);
}

static handle_assert_water_cell_2() {
    auto ecx = GetRegValue("ecx");
    Message("Checking cell (north-south) %x\n", ecx);
}

static handle_assert_water_cell_3() {
    auto esp = GetRegValue("esp");
    auto base = Dword(esp + 0x14 + 0x04);
    auto width = Dword(Dword(esp + 0x14 + 0x08));
    auto ecx = GetRegValue("ecx");
    auto bytes_offset = ecx - base;
    auto x = bytes_offset % width;
    auto y = bytes_offset / width;
    Message("Checking cell (east-west 2) (%d, %d)\n", x, y);
}

static main() {
    AddBpt(0x004445A9);
    SetBptCnd(0x004445A9, "handle_is_direct_path()");

    AddBpt(0x00444767);
    SetBptCnd(0x00444767, "handle_is_direct_path_cell_check_loop()");

    AddBpt(0x00444793);
    SetBptCnd(0x00444793, "handle_assert_water_cell_1()");

    AddBpt(0x004447D7);
    SetBptCnd(0x004447D7, "handle_assert_water_cell_2()");

    AddBpt(0x00444788);
    SetBptCnd(0x00444788, "handle_assert_water_cell_3()");
}
