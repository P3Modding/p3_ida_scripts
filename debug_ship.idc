#include <idc.idc>
#include "lib/lib.idc"

static main() {}

static debug_ship(index) {
    // suspend_process?
    auto ship = get_ship_by_index(index);
    auto str = sprintf("%s\n", ship.to_string());

    auto i;
    for (i = 0; i < 24; i++) {
        str = sprintf("%s  %02x", str, ship.get_weapon(i));
        if (i == 11) {
            str = sprintf("%s\n", str);
        }
    }
    Message("%s\n", str);
}
