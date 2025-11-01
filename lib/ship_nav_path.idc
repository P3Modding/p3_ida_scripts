class ShipNavPath {
    ShipNavPath(address) {
        this.address = address;
    }

    get_first() {
        return Dword(this.address + 0x00);
    }

    get_last() {
        return Dword(this.address + 0x04);
    }

    to_string() {
        return sprintf(
            "(%d, %d)",
            this.get_first(),
            this.get_last());
    }
}
