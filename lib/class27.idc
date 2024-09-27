class Class27 {
    Class27(address) {
        this.address = address;
    }

    get_screen_height() {
        return Dword(this.address + 0x2c);
    }

    get_screen_width() {
        return Dword(this.address + 0x30);
    }

    get_field_800() {
        return Dword(this.address + 0x800);
    }

    get_anim2_oben_rechts_alle_res() {
        return Class74(this.address + 0x808);
    }

    get_anim1_oben_links_800() {
        return Class74(this.address + 0x8e0);
    }

    get_anim41_oben_links_1024() {
        return Class74(this.address + 0x9b8);
    }

    get_anim42_oben_links_1280() {
        return Class74(this.address + 0xa90);
    }

    get_anim4_horizontal_balken_rechts_alle_res() {
        return Class74(this.address + 0xb68);
    }

    get_anim3_vertikal_balken_rechts_alle_res() {
        return Class74(this.address + 0xc40);
    }

    get_anim44_rechts_unten_1024() {
        return Class74(this.address + 0xd18);
    }

    get_anim44_rechts_unten_1280() {
        return Class74(this.address + 0xdf0);
    }

    get_anim59() {
        return Class74(this.address + 0xec8);
    }

    get_() {
        return Class74(this.address + 0xec8);
    }

    to_string() {
        return sprintf(
            "Class27(address=0x%x, screen_height=%d, screen_width=%d, game_speed=%d)",
            this.address,
            this.get_screen_height(),
            this.get_screen_width(),
            this.get_field_800()
        );
    }
}

static get_class27() {
    return Class27(Dword(CLASS27_PTR));
}
