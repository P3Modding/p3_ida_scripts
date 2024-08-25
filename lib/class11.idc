static get_battle_by_index(battle_index) {
    return Battle(Dword(CLASS11_PTR + 0x00) + 0x2f24 * battle_index);
}

static get_battles_allocated() {
    return Byte(CLASS11_PTR + 0x404);
}
