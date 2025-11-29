class Office {
    Office(address) {
        this.address = address;
    }

    get_first_merchant_facility_index() {
        return Word(this.address + 0x2CC);
    }

    get_first_merchant_facility() {
        return GameWorld().get_merchant_facility(this.get_first_merchant_facility_index());
    }

    to_string() {
        return sprintf(
            "Office(address=0x%x, first_merchant_facility=0x%x)",
            this.address,
            this.get_first_merchant_facility_index()
        );
    }
}
