class Merchant {
    Merchant(address) {
        this.address = address;
    }

    first_office_index() {
        return Word(this.address + 0x0C);
    }

    to_string() {
        return sprintf(
            "Merchant(address=0x%x)",
            this.address
        );
    }
}
