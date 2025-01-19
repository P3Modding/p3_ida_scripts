class Class84 {
    Class84(address) {
        this.address = address;
    }

    get_field_14() {
        return Dword(this.address + 0x14);
    }

    get_status() {
        return Dword(this.address + 0x18);
    }

    to_string() {
        return sprintf(
            "Class84(address=0x%x, field_14=0x%x, status=0x%x)",
            this.address,
            this.get_field_14(),
            this.get_status()
        );
    }
}
