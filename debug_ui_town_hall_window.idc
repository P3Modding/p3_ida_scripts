#include <idc.idc>
#include "lib/lib.idc"

static main() {}

static debug_town_hall_window() {
    auto town_hall = get_ui_town_hall_window();
    Message("%s 0x%x\n", town_hall.to_string(), town_hall.address + 0x18E4);
}
