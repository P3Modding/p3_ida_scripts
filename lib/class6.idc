static get_ship_by_index(ship_index) {
    return Ship(Dword(CLASS6_PTR + 0x04) + 0x180 * ship_index);
}

static get_ships_size() {
    return Word(CLASS6_PTR + 0xf4);
}

static get_captain_by_index(captain_index) {
    return Captain(Dword(CLASS6_PTR + 0x00) + 0x10 * captain_index);
}

static get_captains_size() {
    return Word(CLASS6_PTR + 0xf2);
}
