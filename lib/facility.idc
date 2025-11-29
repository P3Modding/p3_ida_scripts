class Facility {
    Facility(address) {
        this.address = address;
    }

    get_efficiency() {
        return Dword(this.address + 0x00);
    }

    get_employees() {
        return Word(this.address + 0x04);
    }

    get_facility_type() {
        return Byte(this.address + 0x06);
    }

    get_town_index() {
        return Byte(this.address + 0x07);
    }

    get_field_8() {
        return Word(this.address + 0x08);
    }

    get_field_a() {
        return Word(this.address + 0x0A);
    }

    get_employees_max() {
        return Word(this.address + 0x0C);
    }

    get_field_e() {
        return Word(this.address + 0x0E);
    }

    to_string() {
        return sprintf(
            "Facility(address=0x%x, efficiency=%d, employees=%d, facility_type=0x%x, field_8=0x%x, field_a=%d, employees_max=%d, field_e=%d)",
            this.address,
            this.get_efficiency(),
            this.get_employees(),
            this.get_facility_type(),
            this.get_field_8(),
            this.get_field_a(),
            this.get_employees_max(),
            this.get_field_e()
        );
    }
}
