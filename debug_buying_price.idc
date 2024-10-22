#include <idc.idc>
#include "lib/lib.idc"

extern break_get_buy_price;

static handle_get_buy_price() {
    auto esp = GetRegValue("esp");
    auto ware_id = Dword(esp + 0x00 + 0x04);
    auto town_index = Dword(esp + 0x00 + 0x08);
    auto buy_amount = Dword(esp + 0x00 + 0x0C);
    if (ware_id == 0x10 && town_index == 0x09) {
        break_get_buy_price = 1;
        Message("handle_get_buy_price Luebeck PigIron\n");
        return 0;
    } else {
        break_get_buy_price = 0;
    }
}

static handle_get_buy_price_prefinal() {
    if (break_get_buy_price) {
        auto value = GetRegValue("ST0");
        Message("computed %f\n", value);
    }
}

static handle_get_buy_price_factor() {
    if (break_get_buy_price) {
        auto value = GetRegValue("ST0");
        Message("factor %f\n", value);
    }
}

static main() {
    break_get_buy_price = 0;
    AddBpt(0x0052E430);
    SetBptCnd(0x0052E430, "handle_get_buy_price()");

    AddBpt(0x0052E6E2);
    SetBptCnd(0x0052E6E2, "handle_get_buy_price_prefinal()");

    AddBpt(0x0052E6A3);
    SetBptCnd(0x0052E6A3, "handle_get_buy_price_factor()");
}
