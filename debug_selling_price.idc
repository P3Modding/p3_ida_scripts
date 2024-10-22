#include <idc.idc>
#include "lib/lib.idc"

extern break_get_sell_price;

static handle_get_sell_price() {
    auto esp = GetRegValue("esp");
    auto ware_id = Dword(esp + 0x00 + 0x04);
    auto town_index = Dword(esp + 0x00 + 0x08);
    auto sell_amount = Dword(esp + 0x00 + 0x0C);
    if (ware_id == 0x10 && town_index == 0x09) {
        break_get_sell_price = 1;
        auto ecx = GetRegValue("ecx");
        auto f = get_float(ecx + 0x64);
        Message("handle_get_sell_price Luebeck PigIron difficulty=%f\n", f);
        return 0;
    } else {
        break_get_sell_price = 0;
    }
}

static handle_get_sell_price_prefinal() {
    if (break_get_sell_price) {
        auto value = GetRegValue("ST0");
        Message("computed %f\n", value);
    }
}

static handle_get_sell_price_factor() {
    if (break_get_sell_price) {
        auto value = GetRegValue("ST0");
        Message("factor %f\n", value);
    }
}

static main() {
    break_get_sell_price = 0;
    AddBpt(0x0052E1D0);
    SetBptCnd(0x0052E1D0, "handle_get_sell_price()");

    AddBpt(0x0052E415);
    SetBptCnd(0x0052E415, "handle_get_sell_price_prefinal()");

    AddBpt(0x0052E3E4);
    SetBptCnd(0x0052E3E4, "handle_get_sell_price_factor()");
}
