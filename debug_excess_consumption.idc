#include <idc.idc>
#include "lib/lib.idc"

extern break_excess_consumption;

static handle_town_excess_consumption() {
    auto town = Town(GetRegValue("ecx"));
    if (town.get_town_index() != 0) {
        break_excess_consumption = 0;
        return 0;
    }

    break_excess_consumption = 1;
    return 0;
}

static handle_town_excess_consumption_reduction() {
    if (!break_excess_consumption) {
        return 0;
    }

    return 1;
}

static main() {
    AddBpt(0x00528630);
    SetBptCnd(0x00528630, "handle_town_excess_consumption()");

    AddBpt(0x005286A7);
    SetBptCnd(0x005286A7, "handle_town_excess_consumption_reduction()");
}
