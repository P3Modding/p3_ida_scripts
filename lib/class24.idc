class Class24 {
    Class24(address) {
        this.address = address;
    }

    get_battle_difficulty_setting() {
        return Byte(this.address + 0x12);
    }

    get_satisfaction_setting() {
        return Byte(this.address + 0x17);
    }

    get_resolution_setting() {
        return Byte(this.address + 0x1f);
    }

    get_colors_setting() {
        return Byte(this.address + 0x20);
    }

    to_string() {
        return sprintf(
            "Class24(address=0x%x, battle_difficulty=%d, satisfaction_difficulty=%d, resolution=%d, colors=%d)",
            this.address,
            this.get_battle_difficulty_setting(),
            this.get_satisfaction_setting(),
            this.get_resolution_setting(),
            this.get_colors_setting());
    }
}

static get_class24() {
    return Class24(Dword(CLASS24_PTR));
}
