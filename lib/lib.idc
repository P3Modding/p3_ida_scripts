#define TOWN_NAMES_PTR  0x006DDA00
#define GAME_WORLD_PTR  0x006DE4A0
#define CLASS44_PTR     0x006DD730
#define CLASS6_PTR      0x006DD7A0
#define CLASS11_PTR     0x006E55D0
#define CLASS22_PTR     0x006E51AC
#define CLASS24_PTR     0x006CC3E8
#define CLASS27_PTR     0x006CBB40
#define CLASS73_PTR_ADDRESS                             0x006CBA64
#define CLASS75_ADDRESS                                 0x006DA820
#define STATIC_UI_SHIPYARD_WINDOW_PTR_ADDRESS           0x006E55C0


#include "battle.idc"
#include "captain.idc"
#include "class6.idc"
#include "class11.idc"
#include "class22.idc"
#include "class24.idc"
#include "class27.idc"
#include "class73.idc"
#include "class74.idc"
#include "class75.idc"
#include "class77.idc"
#include "game_world.idc"
#include "letter.idc"
#include "local_map_ship.idc"
#include "operation.idc"
#include "screen_rectangle.idc"
#include "sea_battle_projectile.idc"
#include "ship.idc"
#include "timestamp.idc"
#include "town.idc"
#include "ui_shipyard_window.idc"


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
