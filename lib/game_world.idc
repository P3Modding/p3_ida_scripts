static get_town_by_index(town_index) {
    return Town(Dword(GAME_WORLD_PTR + 0x68) + 0x9F8 * town_index);
}

static get_day_of_year() {
    return Word(GAME_WORLD_PTR + 0x0004);
}

static get_timestamp() {
    return Dword(GAME_WORLD_PTR + 0x14);
}
