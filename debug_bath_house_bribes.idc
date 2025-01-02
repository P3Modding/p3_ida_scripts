#include <idc.idc>
#include "lib/lib.idc"

static handle_bath_house_bribe_rand_override() {
    SetRegValue(0, "eax");
}

static main() {
    AddBpt(0x005A0914);
    SetBptCnd(0x005A0914, "handle_bath_house_bribe_rand_override()");

    AddBpt(0x005A094F);
    SetBptCnd(0x005A094F, "handle_bath_house_bribe_rand_override()");

    AddBpt(0x005A098A);
    SetBptCnd(0x005A098A, "handle_bath_house_bribe_rand_override()");

    AddBpt(0x005A09C5);
    SetBptCnd(0x005A09C5, "handle_bath_house_bribe_rand_override()");
}
