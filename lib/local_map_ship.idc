class LocalMapShip {
    LocalMapShip(address) {
        this.address = address;
    }

    get_vtable() {
        return Dword(this.address);
    }

    get_ship_index() {
        return Dword(this.address + 0x04);
    }

    get_x() {
        return Word(this.address + 0xa);
    }

    get_y() {
        return Word(this.address + 0xe);
    }

    get_field_11_direction() {
        return Byte(this.address + 0x11);
    }

    get_field_1c_speed() {
        return Dword(this.address + 0x1c);
    }

    get_sails_level_current() {
        return Byte(this.address + 0x26);
    }

    get_field_12a() {
        return Byte(this.address + 0x12a);
    }

    get_field_battle() {
        return Battle(Dword(this.address + 0x12c));
    }

    get_field_138() {
        return Byte(this.address + 0x138);
    }

    get_sails_level_setting() {
        return Byte(this.address + 0x148);
    }

    to_string() {
        return sprintf(
            "LocalMapShip(address=0x%x, ship_index=0x%x, x=%d (0x%x), y=%d (0x%x), field_11_direction=0x%x, speed=%d, sails_level_current=%d, field_12a=0x%02x, field_138=%d, sails_level_setting=%d)",
            this.address,
            this.get_ship_index(),
            this.get_x(),
            this.get_x(),
            this.get_y(),
            this.get_y(),
            this.get_field_11_direction(),
            this.get_field_1c_speed(),
            this.get_sails_level_current(),
            this.get_field_12a(),
            this.get_field_138(),
            this.get_sails_level_setting());
    }
}
