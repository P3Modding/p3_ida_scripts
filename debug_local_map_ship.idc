#include <idc.idc>
#include "lib/lib.idc"

static main() {}

static debug_local_map_battle_ship(battle_index, index) {
    // suspend_process?
    auto battle = get_battle_by_index(battle_index);
    auto local_map_ship = battle.get_local_map_ship(index);
    auto str = local_map_ship.to_string();
    str = str + "\n\n";
    Message(str);
}
