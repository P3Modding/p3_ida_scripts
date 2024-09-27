class ScreenRectangle {
    ScreenRectangle(address) {
        this.address = address;
    }

    get_field_0() {
        return Dword(this.address + 0x00);
    }

    get_field_4() {
        return Dword(this.address + 0x04);
    }

    get_field_8() {
        return Dword(this.address + 0x08);
    }

    set_width(width) {
        patch_dbg_dword(this.address + 0x08, width);
    }

    get_field_c() {
        return Dword(this.address + 0x0c);
    }

    set_height(height) {
        patch_dbg_dword(this.address + 0x0c, height);
    }

    to_string() {
        return sprintf(
            "ScreenRectangle(address=0x%x, field_0_x1=%d, field_4_y1=%d, field_8_x1=%d, field_c_y2=%d)",
            this.address,
            this.get_field_0(),
            this.get_field_4(),
            this.get_field_8(),
            this.get_field_c()
        );
    }
}
