class Ship {
    Ship(address) {
        this.address = address;
    }

    get_owner_index() {
        return Byte(this.address + 0x00);
    }

    get_max_health() {
        return Dword(this.address + 0x14);
    }

    get_current_health() {
        return Dword(this.address + 0x18);
    }

    get_x() {
        return Dword(this.address + 0x1C);
    }

    get_y() {
        return Dword(this.address + 0x20);
    }

    get_y_high() {
        return Word(this.address + 0x22);
    }

    get_current_town_id() {
        return Byte(this.address + 0x39);
    }

    get_damage_thing() {
        return Byte(this.address + 0x3f);
    }

    get_sailors() {
        return Word(this.address + 0x40);
    }

    get_captain_index() {
        return Word(this.address + 0x42);
    }

    get_captain() {
        auto captain_index = Word(this.address + 0x42);
        if (captain_index >= get_captains_size()) {
            return 0;
        }

        return get_captain_by_index(captain_index);
    }

    get_target_index_1() {
        return Word(this.address + 0x0050);
    }

    get_target_index_2() {
        return Word(this.address + 0x0052);
    }

    get_status() {
        return Word(this.address + 0x134);
    }

    get_weapon(index) {
        return Byte(this.address + 0x13c + index);
    }

    get_is_pirate() {
        return Byte(this.address + 0x15c);
    }

    get_ship_name() {
        return GetString(this.address + 0x160, -1, 0);
    }

    to_string() {
        return sprintf(
            "Ship(address=0x%x, owner_index=0x%x, max_health=%u, current_health=%u, x=0x%x, y=0x%x, current_town_id=0x%x, damage_thing=%d, captain_index=0x%x, status=0x%x, ship_name=%s, is_pirate=%d, 0x%x 0x%x)",
            this.address,
            this.get_owner_index(),
            this.get_max_health(),
            this.get_current_health(),
            this.get_x(),
            this.get_y(),
            this.get_current_town_id(),
            this.get_damage_thing(),
            this.get_captain_index(),
            this.get_status(),
            this.get_ship_name(),
            this.get_is_pirate(),
            this.get_target_index_1(),
            this.get_target_index_2());
    }
}
