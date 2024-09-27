class Class73 {
    Class73(address) {
        this.address = address;
    }

    get_screen_width() {
        return Dword(this.address + 0x2c);
    }

    get_screen_height() {
        return Dword(this.address + 0x30);
    }

    get_() {
        return Class74(this.address + 0x164);
    }

    to_string() {
        return sprintf(
            "Class73(address=0x%x, width=%d, height=%d)",
            this.address,
            this.get_screen_width(),
            this.get_screen_height()
        );
    }
}

static get_class73() {
    return Class73(Dword(CLASS73_PTR_ADDRESS));
}
