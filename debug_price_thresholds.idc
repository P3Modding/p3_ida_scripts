#include <idc.idc>
#include "lib/lib.idc"

static handle_load_wine_t1_september() {
    auto wine_t1 = GetRegValue("ecx");
    Message("old wine t1 = %d\n", wine_t1);
}

static handle_write_updated_wine_t1() {
    auto wine_t1 = GetRegValue("edx");
    Message("new wine t1 = %d\n", wine_t1);
}

static main() {
    AddBpt(0x00528230);
    SetBptCnd(0x00528230, "handle_load_wine_t1_september()");

    AddBpt(0x005282C9);
    SetBptCnd(0x005282C9, "handle_write_updated_wine_t1()");
}
