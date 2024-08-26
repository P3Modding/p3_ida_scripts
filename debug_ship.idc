#include <idc.idc>
#include "lib/lib.idc"

static main() {}

static debug_ship(index) {
    // suspend_process?
    auto ship = get_ship_by_index(index);
    auto str = ship.to_string() + "\n";

    // Artillery
    auto i;
    for (i = 0; i < 24; i++) {
        str = sprintf("%s  %02x", str, ship.get_weapon(i));
        if (i == 11 || i == 23) {
            str = str + "\n";
        }
    }

    // Captain
    auto captain = ship.get_captain();
    if (captain) {
        str = str + captain.to_string() + "\n";
    }

    str = str + "\n\n";
    Message(str);
}
