#define TOWN_NAMES_PTR  0x006DDA00
#define GAME_WORLD_PTR  0x006DE4A0
#define CLASS44_PTR     0x006DD730
#define CLASS6_PTR      0x006DD7A0
#define CLASS11_PTR     0x006E55D0
#define CLASS22_PTR     0x006E51AC

#include "battle.idc"
#include "class6.idc"
#include "class11.idc"
#include "class22.idc"
#include "class55.idc"
#include "game_world.idc"
#include "letter.idc"
#include "town.idc"
#include "ship.idc"
#include "operation.idc"

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
