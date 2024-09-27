class Class74 {
    //anim
    Class74(address) {
        this.address = address;
    }

    get_pos_x() {
        return Dword(this.address + 0x20);
    }

    set_pos_x(pos) {
        patch_dbg_dword(this.address + 0x20, pos);
    }

    get_pos_y() {
        return Dword(this.address + 0x24);
    }

    get_field_94_a4_len() {
        return Dword(this.address + 0x94);
    }

    get_field_a0() {
        return Dword(this.address + 0xa0);
    }

    get_field_a0_entry(index) {
        return ScreenRectangle(Dword(Dword(this.address + 0xa0) + index * 4));
    }

    get_field_a4() {
        return Dword(this.address + 0xa4);
    }

    get_field_a4_entry(index) {
        return Dword(Dword(this.address + 0xa4) + index * 4);
    }

    to_string() {
        return sprintf(
            "Class74(address=0x%x, a4_len=%d, field_a0=0x%x)",
            this.address,
            this.get_field_94_a4_len(),
            this.get_field_a0()
        );
    }
}
