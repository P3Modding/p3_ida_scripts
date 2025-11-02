class Convoy {
    Convoy(address) {
        this.address = address;
    }

    get_field_0c() {
        return Dword(this.address + 0x0c);
    }

    get_expedition_money() {
        return Dword(this.address + 0x20);
    }

    get_field_38() {
        return Word(this.address + 0x38);
    }

    to_string() {
        return sprintf(
            "Convoy(address=0x%x, expedition_money=%d, field_0c=%d, field_38=0x%x)",
            this.address,
            this.get_expedition_money(),
            this.get_field_0c(),
            this.get_field_38());
    }
}
