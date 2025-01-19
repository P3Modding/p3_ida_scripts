class Class85 {
    Class85(address) {
        this.address = address;
    }

    get_field_0() {
        return Dword(this.address + 0x00);
    }

    get_field_144(index) {
        return Byte(this.address + 0x144 + index);
    }

    get_field_16c(index) {
        return Byte(this.address + 0x16c + index);
    }

    get_field_194(index) {
        return Byte(this.address + 0x194 + index);
    }

    to_string() {
        auto arr_144 = "";
        auto arr_16c = "";
        auto arr_194 = "";
        auto i;
        for (i = 0; i < 40; i++) {
            arr_144 = arr_144 + form("%02x", this.get_field_144(i));
            arr_16c = arr_16c + form("%02x", this.get_field_16c(i));
            arr_194 = arr_16c + form("%02x", this.get_field_194(i));
        }
        return sprintf(
            "Class85(address=0x%x, field_0=0x%x, field_144=%s, field_16c=%s, field_194=%s)",
            this.address,
            this.get_field_0(),
            arr_144,
            arr_16c,
            arr_194
        );
    }
}
