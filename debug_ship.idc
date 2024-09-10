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

    for (i = 0; i < 24;) {
        auto w1 = ship_weapon_str(ship.get_weapon(i));
        auto w2 = ship_weapon_str(ship.get_weapon(i+1));
        str = str + w1 + w2;
        i = i + 4;
    }
    str = str + "\n";
    for (i = 2; i < 24;) {
        w1 = ship_weapon_str(ship.get_weapon(i));
        w2 = ship_weapon_str(ship.get_weapon(i+1));
        str = str + w1 + w2;
        i = i + 4;
    }
    str = str + "\n";

    // Captain
    auto captain = ship.get_captain();
    if (captain) {
        str = str + captain.to_string() + "\n";
    }

    str = str + "\n\n";
    Message(str);
}
