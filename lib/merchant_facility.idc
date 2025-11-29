class MerchantFacility {
    MerchantFacility(address) {
        this.address = address;
    }

    get_facility() {
        return Facility(this.address);
    }

    to_string() {
        return sprintf(
            "MerchantFacility(address=0x%x, facility=%s)",
            this.address,
            this.get_facility().to_string()
        );
    }
}
