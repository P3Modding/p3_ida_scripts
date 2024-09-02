#include <idc.idc>
#include "lib/lib.idc"

static main() {}

static debug_town(index) {
    // suspend_process?
    auto town = get_town_by_index(index);
    auto str = town.to_string() + "\n";

    auto shipyard_experience = town.get_shipyard_experience();
    auto shipyard_something = town.get_shipyard_something();
    str = str + sprintf("  Shipyard XP: %d (0x%x)\n", shipyard_experience, shipyard_experience);
    str = str + sprintf("  Shipyard Something: %d (0x%x)\n", shipyard_something, shipyard_something);

    str = str + "\n\n";
    Message(str);
}
