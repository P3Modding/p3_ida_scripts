class LoanApplicant {
    LoanApplicant(address) {
        this.address = address;
    }

    get_field_0() {
        return Byte(this.address + 0x00);
    }

    get_field_1() {
        return Byte(this.address + 0x01);
    }

    get_field_2() {
        return Byte(this.address + 0x02);
    }

    get_weeks() {
        return Byte(this.address + 0x03);
    }

    get_amount() {
        return Word(this.address + 0x04);
    }

    to_string() {
        return sprintf(
            "LoanApplicant(address=0x%x, field_0=0x%x, field_1=0x%x, field_2=0x%x, weeks=%d, amount=%d)",
            this.address,
            this.get_field_0(),
            this.get_field_1(),
            this.get_field_2(),
            this.get_weeks(),
            this.get_amount()
        );
    }
}
