#define TOWN_NAMES_PTR  0x006DDA00
#define GAME_WORLD_PTR  0x006DE4A0
#define CLASS44_PTR     0x006DD730
#define CLASS6_PTR      0x006DD7A0
#define CLASS11_PTR     0x006E55D0
#define CLASS22_PTR     0x006E51AC
#define CLASS24_PTR     0x006CC3E8
#define CLASS27_PTR     0x006CBB40
#define CLASS48_PTR_ADDRESS                             0x006CC7E0
#define CLASS73_PTR_ADDRESS                             0x006CBA64
#define CLASS75_ADDRESS                                 0x006DA820
#define UI_MONEY_LENDER_WINDOW_PTR_ADDRESS              0x006E5534
#define STATIC_UI_SHIPYARD_WINDOW_PTR_ADDRESS           0x006E55C0
#define UI_TOWN_HALL_SIDEMENU_PTR_ADDRESS               0x006E5500
#define UI_TOWN_HALL_WINDOW_PTR_ADDRESS                 0x006E558C
#define SCHEDULED_TASKS_ADDRESS                         0x006DD73C


#include "alderman_mission.idc"
#include "battle.idc"
#include "captain.idc"
#include "class6.idc"
#include "class11.idc"
#include "class22.idc"
#include "class24.idc"
#include "class27.idc"
#include "class48.idc"
#include "class73.idc"
#include "class74.idc"
#include "class75.idc"
#include "class77.idc"
#include "class84.idc"
#include "class85.idc"
#include "game_world.idc"
#include "letter.idc"
#include "loan_applicant.idc"
#include "local_map_ship.idc"
#include "operation.idc"
#include "operations.idc"
#include "scheduled_task.idc"
#include "screen_rectangle.idc"
#include "sea_battle_projectile.idc"
#include "ship.idc"
#include "short_point.idc"
#include "timestamp.idc"
#include "town.idc"
#include "ui_money_lender_window.idc"
#include "ui_shipyard_window.idc"
#include "ui_town_hall_sidemenu.idc"
#include "ui_town_hall_window.idc"


static break_at(offset, handler) {
    auto address = get_imagebase() + offset;
    auto bp = AddBpt(address);
    SetBptCnd(address, handler);
    Message("BP 0x%08x created\n", address);
}

static break_at_abs(address, handler) {
    auto bp = AddBpt(address);
    SetBptCnd(address, handler);
    Message("BP 0x%08x created\n", address);
}

static patch_dbg_dword(address, value) {
    patch_dbg_byte(address, value & 0xff);
    patch_dbg_byte(address+1, (value >> 8) & 0xff);
    patch_dbg_byte(address+2, (value >> 16) & 0xff);
    patch_dbg_byte(address+3, (value >> 24) & 0xff);
}

static ceililing_div(value, div) {
    return (value + div-1) / div;
}

static ware_string(ware) {
    if (ware == 0x00) {
        return "Grain";
    } else if (ware == 0x01) {
        return "Meat";
    } else if (ware == 0x02) {
        return "Fish";
    } else if (ware == 0x03) {
        return "Beer";
    } else if (ware == 0x04) {
        return "Salt";
    } else if (ware == 0x05) {
        return "Honey";
    } else if (ware == 0x06) {
        return "Spices";
    } else if (ware == 0x07) {
        return "Wine";
    } else if (ware == 0x08) {
        return "Cloth";
    } else if (ware == 0x09) {
        return "Skins";
    } else if (ware == 0x0a) {
        return "WhaleOil";
    } else if (ware == 0x0b) {
        return "Timber";
    } else if (ware == 0x0c) {
        return "IronGoods";
    } else if (ware == 0x0d) {
        return "Leather";
    } else if (ware == 0x0e) {
        return "Wool";
    } else if (ware == 0x0f) {
        return "Pitch";
    } else if (ware == 0x10) {
        return "PigIron";
    } else if (ware == 0x11) {
        return "Hemp";
    } else if (ware == 0x12) {
        return "Pottery";
    } else if (ware == 0x13) {
        return "Bricks";
    }
}

static facility_string(ware) {
    if (ware == 0x00) {
        return "Militia";
    } else if (ware == 0x01) {
        return "Shipyard";
    } else if (ware == 0x02) {
        return "Construction";
    } else if (ware == 0x03) {
        return "Weaponsmith";
    } else if (ware == 0x04) {
        return "HuntingLodge";
    } else if (ware == 0x05) {
        return "FishermansHouse";
    } else if (ware == 0x06) {
        return "Brewery";
    } else if (ware == 0x07) {
        return "Workshop";
    } else if (ware == 0x08) {
        return "Apiary";
    } else if (ware == 0x09) {
        return "GrainFarm";
    } else if (ware == 0x0a) {
        return "CattleFarm";
    } else if (ware == 0x0b) {
        return "Sawmill";
    } else if (ware == 0x0c) {
        return "WeavingMill";
    } else if (ware == 0x0d) {
        return "Saltery";
    } else if (ware == 0x0e) {
        return "Ironsmelter";
    } else if (ware == 0x0f) {
        return "SheepFarm";
    } else if (ware == 0x10) {
        return "Vineyard";
    } else if (ware == 0x11) {
        return "Pottery";
    } else if (ware == 0x12) {
        return "Brickworks";
    } else if (ware == 0x13) {
        return "Pitchmaker";
    } else if (ware == 0x14) {
        return "HempFarm";
    }
}

static town_string(town_id) {
    if (town_id == 0x00) {
        return "Edinburgh";
    } else if (town_id == 0x01) {
        return "Newcastle";
    } else if (town_id == 0x02) {
        return "Scarborough";
    } else if (town_id == 0x03) {
        return "Boston";
    } else if (town_id == 0x04) {
        return "Boston";
    } else if (town_id == 0x05) {
        return "London";
    } else if (town_id == 0x06) {
        return "Haarlem";
    } else if (town_id == 0x07) {
        return "Harlingen";
    } else if (town_id == 0x08) {
        return "Groningen";
    } else if (town_id == 0x09) {
        return "Cologne";
    } else if (town_id == 0x0a) {
        return "Bremen";
    } else if (town_id == 0x0b) {
        return "Ripen";
    } else if (town_id == 0x0c) {
        return "Hamburg";
    } else if (town_id == 0x0d) {
        return "Flensburg";
    } else if (town_id == 0x0e) {
        return "Luebeck";
    } else if (town_id == 0x0f) {
        return "Rostock";
    } else if (town_id == 0x10) {
        return "Bergen";
    } else if (town_id == 0x11) {
        return "Stavanger";
    } else if (town_id == 0x12) {
        return "Toensberg";
    } else if (town_id == 0x13) {
        return "Oslo";
    } else if (town_id == 0x14) {
        return "Aalborg";
    } else if (town_id == 0x15) {
        return "Goeteborg";
    } else if (town_id == 0x16) {
        return "Naestved";
    } else if (town_id == 0x17) {
        return "Malmoe";
    } else if (town_id == 0x18) {
        return "Ahus";
    } else if (town_id == 0x19) {
        return "Stockholm";
    } else if (town_id == 0x1a) {
        return "Visby";
    } else if (town_id == 0x1b) {
        return "Helsinki";
    } else if (town_id == 0x1c) {
        return "Stettin";
    } else if (town_id == 0x1d) {
        return "Ruegenwald";
    } else if (town_id == 0x1e) {
        return "Gdansk";
    } else if (town_id == 0x1f) {
        return "Torun";
    } else if (town_id == 0x20) {
        return "Koenigsberg";
    } else if (town_id == 0x21) {
        return "Memel";
    } else if (town_id == 0x22) {
        return "Windau";
    } else if (town_id == 0x23) {
        return "Riga";
    } else if (town_id == 0x24) {
        return "Pernau";
    } else if (town_id == 0x25) {
        return "Reval";
    } else if (town_id == 0x26) {
        return "Ladoga";
    } else if (town_id == 0x27) {
        return "Novgorod";
    }
}
