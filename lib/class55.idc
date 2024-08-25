class Class55 {
    Class55(address) {
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

    get_field_11_distance_thing_1() {
        return Byte(this.address + 0x11);
    }

    get_field_12c() {
        return Dword(this.address + 0x12c);
    }

    to_string() {
        return sprintf(
            "Class55(address=0x%x, x=%d, y=%d, field_11=0x%x, field_12c=0x%x)",
            this.address,
            this.get_x(),
            this.get_y(),
            this.get_field_11_distance_thing_1(),
            this.get_field_12c());
    }
}
