class Battle {
    Battle(address) {
        this.address = address;
    }

    get_class55(index) {
        return Class55(Dword(Dword(this.address + 0x04) + 4 * index));
    }

    get_class55s_len() {
        return Word(this.address + 0x14);
    }

    get_field_18() {
        return Dword(this.address + 0x18);
    }

    get_field_20() {
        return Word(this.address + 0x20);
    }

    get_field_56() {
        return Word(this.address + 0x56);
    }

    get_field_58() {
        return Word(this.address + 0x58);
    }

    get_field_5a() {
        return Word(this.address + 0x5a);
    }

    get_index() {
        return Word(this.address + 0x662);
    }

    get_field_668() {
        return Dword(this.address + 0x668);
    }

    get_field_670_wind_direction() {
        return Byte(this.address + 0x670);
    }

    get_field_acc() {
        return Word(this.address + 0xacc);
    }

    to_string() {
        return sprintf(
            "Battle(address=0x%x, field_18=0x%x, field_20=0x%x, field_56=0x%x, field_58=0x%x, field_5a=0x%x, field_668=0x%x, field_670_wind_direction=0x%x, field_acc=0x%x)",
            this.address,
            this.get_field_18(),
            this.get_field_20(),
            this.get_field_56(),
            this.get_field_58(),
            this.get_field_5a(),
            this.get_field_668(),
            this.get_field_670_wind_direction(),
            this.get_field_acc());
    }
}