class Class77 {
    Class77(address) {
        this.address = address;
        auto vtable = Dword(address);
        if (vtable != 0x00670B28) {
            // This happens, apparently? Lazy loading?
            // Message("WARNING: Class77 with unexpected vtable 0x%x\n", vtable);
        }
    }

    get_vtable() {
        return Dword(this.address);
    }

    get_texture_ptr() {
        return Dword(this.address + 0x04);
    }

    get_texture_id() {
        return Dword(this.address + 0x28);
    }

    is_initialized() {
        auto vtable = Dword(this.address);
        return vtable == 0x00670B28;
    }

    to_string() {
        return sprintf(
            "Class77(address=0x%x, vtable=0x%x, texture_handle=0x%x, texture_id=%d)",
            this.address,
            this.get_vtable(),
            this.get_texture_ptr(),
            this.get_texture_id()
        );
    }
}
