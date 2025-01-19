class Operations {
    Operations() {
        this.address = 0x006DF2F0;
    }

    get_field_0() {
        return Dword(this.address + 0x00);
    }

    get_class85() {
        return Class85(Dword(this.address + 0x0c));
    }

    get_field_10() {
        return Dword(this.address + 0x10);
    }

    get_field_2c() {
        return Dword(this.address + 0x2c);
    }

    get_class84(index) {
        auto base_ptr = Dword(this.address + 0x44);
        auto ptr = base_ptr + index * 0x24;
        return Class84(ptr);
    }

    get_pending_ops_count() {
        return Word(0x006DF346);
    }

    get_pending_op(index) {
        return Operation(0x6DF348 + 0x14 * index);
    }

    to_string() {
        return sprintf(
            "Operations(address=0x%x, field_0=0x%x, field_10=0x%x, field_2c=0x%x)",
            this.address,
            this.get_field_0(),
            this.get_field_10(),
            this.get_field_2c()
        );
    }
}
