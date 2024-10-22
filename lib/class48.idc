class Class48 {
    Class48(address) {
        this.address = address;
    }

    to_string() {
        return sprintf(
            "Class48(address=0x%x)",
            this.address);
    }
}

static get_class48() {
    return Class48(Dword(CLASS48_PTR_ADDRESS));
}
