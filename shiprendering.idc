#include <idc.idc>
#include "lib/lib.idc"


static handle_shiprendering_buffsfilled() {
    auto i;
    auto ships_size = get_ships_size();
    auto buf1 = Dword(GetRegValue("esp") + 0x24);
    auto buf2 = Dword(GetRegValue("esp") + 0x20);
    auto drawn_ships = GetRegValue("ebp");

    // Log original ships
    /*
    for (i = 0; i < drawn_ships; i++) {
        auto ship_index = Dword(buf2 + 4*i);
        auto ship_y = Dword(buf1 + 4*i);
        auto ship = get_ship_by_index(ship_index);
        Message("Ship 0x%x y=0x%x %s\n", ship_index, ship_y, ship.to_string());
    }
    */

    // Enable all ships
    auto new_ships_size = 0;
    for (i = 0; i < ships_size; i++) {
        auto ship2 = get_ship_by_index(i);
        auto status = ship2.get_status();

        if (ship2.get_current_health() == 0) {
            continue;
        }
        if (status != 0x12 && status != 0xf) {
            continue;
        }

        patch_dbg_dword(buf1 + 4*new_ships_size, ship2.get_y_high());   // write ship ypos
        patch_dbg_dword(buf2 + 4*new_ships_size, i);                    // Write ship index
        new_ships_size = new_ships_size + 1;
    }
    SetRegValue(new_ships_size, "ebp");

    return 0;
}

static main() {
    Message("\n\n\n");
    auto ships_size = get_ships_size();
    //auto bp3 = AddBpt(0x00451B58);
    //SetBptCnd(0x00451B58, "handle_shiprendering_buffsfilled()");

    auto i;
    for (i = 0; i < ships_size; i++) {
        auto ship = get_ship_by_index(i);
        if (ship.get_status() != 255 && ship.get_current_health() > 0) {
            Message("%s\n", ship.to_string());
        }
    }
}
