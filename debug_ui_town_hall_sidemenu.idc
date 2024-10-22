#include <idc.idc>
#include "lib/lib.idc"

static main() {
    auto town_hall_sidemenu = get_ui_town_hall_sidemenu();
    Message("%s 0x%x\n", town_hall_sidemenu.to_string(), town_hall_sidemenu.address + 0x8F7);
}
