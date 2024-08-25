class Class22 {
    Class22(address) {
        this.address = address;
    }

    get_field_14() {
        return Dword(this.address + 0x14);
    }

    get_field_18() {
        return Dword(this.address + 0x18);
    }

    get_field_4d0() {
        return Dword(this.address + 0x4d0);
    }

    get_field_4d4() {
        return Dword(this.address + 0x4d4);
    }

    get_field_510() {
        return Dword(this.address + 0x510);
    }

    get_field_514() {
        return Dword(this.address + 0x514);
    }

    get_field_c314() {
        return Dword(this.address + 0xc314);
    }

    get_field_c318() {
        return Dword(this.address + 0xc318);
    }

    to_string() {
        auto c310_size = 4 * this.get_field_c314() * this.get_field_c318();
        return sprintf(
            "Class22(address=0x%x, field_14=0x%x, field_18=0x%x, field_4d0=%d, field_4d4=%d, field_510=%d, field_514=%d, field_c314=%d, field_c318=%d, c310_size=0x%x)",
            this.address,
            this.get_field_14(),
            this.get_field_18(),
            this.get_field_4d0(),
            this.get_field_4d4(),
            this.get_field_510(),
            this.get_field_514(),
            this.get_field_c314(),
            this.get_field_c318(),
            c310_size);
    }
}

static get_class22() {
    return Class22(Dword(CLASS22_PTR));
}