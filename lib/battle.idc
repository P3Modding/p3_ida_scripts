class Battle {
    Battle(address) {
        this.address = address;
    }

    get_local_map_ship(index) {
        return LocalMapShip(Dword(Dword(this.address + 0x04) + 4 * index));
    }

    get_local_map_ships_len() {
        return Word(this.address + 0x14);
    }

    get_field_18() {
        return Dword(this.address + 0x18);
    }

    get_field_18_byte(index) {
        return Byte(Dword(this.address + 0x18) + index);
    }

    get_field_1c() {
        return Dword(this.address + 0x1c);
    }

    get_field_1c_target(index) {
        return Word(Dword(this.address + 0x1c) + index * 2);
    }

    get_class62(index) {
        return Class62(Dword(this.address + 0x18) + index * 0x20);
    }

    get_field_20() {
        return Word(this.address + 0x20);
    }

    get_field_2c() {
        return Dword(this.address + 0x2c);
    }

    get_field_34() {
        return Word(this.address + 0x34);
    }

    get_field_50() {
        return Dword(this.address + 0x50);
    }

    get_field_4c_target(index1, index2) {
        return Dword(Dword(Dword(this.address + 0x4c) + 4 * index1) + 4 * index2);
    }

    get_field_48_target(index1, index2) {
        return Dword(Dword(Dword(this.address + 0x48) + 4 * index1) + 4 * index2);
    }

    get_field_50_target(index1, index2) {
        return Dword(Dword(Dword(this.address + 0x50) + 4 * index1) + 4 * index2);
    }

    get_field_54() {
        return Word(this.address + 0x54);
    }

    get_field_56() {
        return Word(this.address + 0x56);
    }

    get_field_58() {
        return Word(this.address + 0x58);
    }

    get_field_5a() {
        return Word(this.address + 0x5a);
    }

    get_index() {
        return Word(this.address + 0x662);
    }

    get_field_668() {
        return Dword(this.address + 0x668);
    }

    get_projectile(index) {
        return SeaBattleProjectile(Dword(Dword(this.address + 0x668) + index * 4));
    }

    get_field_670_wind_direction() {
        return Byte(this.address + 0x670);
    }

    get_field_acc() {
        return Word(this.address + 0xacc);
    }

    to_string() {
        return sprintf(
            "Battle(address=0x%x, field_18=0x%x, field_1c=0x%x, field_20=0x%x, field_2c=0x%x, field_34=%d, field_50=0x%x, field_54=0x%x, field_56=0x%x, field_58=0x%x, field_5a=0x%x, field_668=0x%x, field_670_wind_direction=0x%x, field_acc=0x%x)",
            this.address,
            this.get_field_18(),
            this.get_field_1c(),
            this.get_field_20(),
            this.get_field_2c(),
            this.get_field_34(),
            this.get_field_50(),
            this.get_field_54(),
            this.get_field_56(),
            this.get_field_58(),
            this.get_field_5a(),
            this.get_field_668(),
            this.get_field_670_wind_direction(),
            this.get_field_acc());
    }
}

class Class62 {
    Class62(address) {
        this.address = address;
    }

    to_string() {
        auto str = sprintf("Class62(address=0x%x, data= ", this.address);
        auto i;
        for (i = 0; i < 0x20; i++) {
            str = str + sprintf("0x%02x ", Byte(this.address + i));
        }
        str = str + ")";
        return str;
    }
}