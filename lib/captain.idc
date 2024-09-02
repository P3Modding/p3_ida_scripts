class Captain {
    Captain(address) {
        this.address = address;
    }

    get_index() {
        return Word(this.address);
    }

    get_field_8() {
        return Byte(this.address + 0x08);
    }

    get_field_navigation_skill() {
        return Byte(this.address + 0x09);
    }

    get_field_combat_skill() {
        return Byte(this.address + 0x0b);
    }

    get_daily_wage() {
        return Word(this.address + 0x0c);
    }

    to_string() {
        return sprintf(
            "Captain(address=0x%x, index=0x%x, field_8=%d, navigation_skill=%d, combat_skill=%d, daily_wage=%d)",
            this.address,
            this.get_index(),
            this.get_field_8(),
            this.get_field_navigation_skill(),
            this.get_field_combat_skill(),
            this.get_daily_wage());
    }
}
