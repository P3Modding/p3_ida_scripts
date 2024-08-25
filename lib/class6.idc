static get_ship_by_index(ship_index) {
    return Ship(Dword(CLASS6_PTR + 0x04) + 0x180 * ship_index);
}

static get_ships_size() {
    return Word(CLASS6_PTR + 0xf4);
}