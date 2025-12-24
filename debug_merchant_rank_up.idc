#include <idc.idc>
#include "lib/lib.idc"


static handle_try_rank_up() {
    auto game_world = GameWorld();
    auto merchant_index = GetRegValue("al");
    if (merchant_index != 0x24) {
        return 0;
    }
    auto town_index = Dword(GetRegValue("esp")+0x3c);
    Message(
        "handle_try_rank_up merchant=0x%x town=0x%x %d.%d.%d\n",
        merchant_index,
        town_index,
        game_world.get_day_of_month(),
        game_world.get_month()+1,
        game_world.get_year());
    if (merchant_index == 0x24 && town_index == 0x08) {
        return 1;
    }
}

static main() {
    AddBpt(0x004F7633);
    SetBptCnd(0x004F7633, "handle_try_rank_up()");
}
