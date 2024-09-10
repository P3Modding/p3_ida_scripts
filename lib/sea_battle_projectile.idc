class SeaBattleProjectile {
    SeaBattleProjectile(address) {
        this.address = address;
    }

    get_x() {
        return TO_LONG(Dword(this.address + 0x4));
    }

    get_y() {
        return TO_LONG(Dword(this.address + 0x8));
    }

    get_dx() {
        return TO_LONG(Dword(this.address + 0xc));
    }

    get_dy() {
        return TO_LONG(Dword(this.address + 0x10));
    }

    get_damage() {
        return TO_LONG(Dword(this.address + 0x14));
    }

    to_string() {
        return sprintf(
            "SeaBattleProjectile(address=0x%x, x=%d, y=%d , dx=%d, dy=%d, damage=%d)",
            this.address,
            this.get_x() >> 16,
            this.get_y() >> 16,
            this.get_dx() >> 16,
            this.get_dy() >> 16,
            this.get_damage());
    }
}
