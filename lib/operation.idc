// 0x00
class OperationSetShipDestination {
    OperationSetShipDestination(address) {
        this.address = address;
    }

    get_ship_index() {
        return Dword(this.address + 0x00);
    }

    get_town_index() {
        return Dword(this.address + 0x04);
    }

    get_x() {
        return Dword(this.address + 0x08);
    }

    get_y() {
        return Dword(this.address + 0x0c);
    }

    to_string() {
        return form(
            "OperationSetShipDestination(address=%x, ship_index=0x%x, town_index=0x%x, x=0x%x, y=0x%x)",
            this.address,
            this.get_ship_index(),
            this.get_town_index(),
            this.get_x(),
            this.get_y());
    }
}

// 0x0d
class OperationTogglePiracy {
    OperationTogglePiracy(address) {
        this.address = address;
    }

    get_ship_index() {
        return Dword(this.address + 0x00);
    }

    get_to_pirate() {
        return Dword(this.address + 0x04);
    }

    to_string() {
        return form(
            "OperationTogglePiracy(address=%x, ship_index=0x%x, to_pirate=0x%x)",
            this.address,
            this.get_ship_index(),
            this.get_to_pirate());
    }
}

// 0x0e
class OperationAttackShip {
    OperationAttackShip(address) {
        this.address = address;
    }

    get_attacker_index() {
        return Dword(this.address + 0x00);
    }

    get_defender_index() {
        return Dword(this.address + 0x04);
    }

    to_string() {
        return form(
            "OperationAttackShip(address=%x, attacker_index=0x%x, defender_index=0x%x)",
            this.address,
            this.get_attacker_index(),
            this.get_defender_index());
    }
}

// 0x61
class OperationAnnounceCelebration {
    OperationAnnounceCelebration(address) {
        this.address = address;
    }

    get_merchant_index() {
        return Dword(this.address + 0x00);
    }

    get_timestamp() {
        return Dword(this.address + 0x04);
    }

    get_town_index() {
        return Dword(this.address + 0x08);
    }

    get_cost() {
        return Dword(this.address + 0x0C);
    }

    to_string() {
        return form(
            "OperationAnnounceCelebration(address=0x%x, merchant_index=0x%x, timestamp=0x%x, town_index=0x%x, cost=%d)",
            this.address,
            this.get_merchant_index(),
            this.get_timestamp(),
            this.get_town_index(),
            this.get_cost());
    }
}

// 0x92
class OperationSeaBattleShipVolley {
    OperationSeaBattleShipVolley(address) {
        this.address = address;
    }

    get_battle_index_index() {
        return Byte(this.address + 0x00);
    }

    get_field_1() {
        return Byte(this.address + 0x01);
    }

    get_field_2() {
        return Byte(this.address + 0x02);
    }

    get_field_3() {
        return Byte(this.address + 0x03);
    }

    get_field_4() {
        return Dword(this.address + 0x04);
    }

    get_field_8() {
        return Dword(this.address + 0x08);
    }

    to_string() {
        return form(
            "OperationSeaBattleShipVolley(address=0x%x, battle_index=0x%x, field1=0x%x, field2=0x%x, field3=0x%x, field4=0x%x, field8=0x%x)",
            this.address,
            this.get_battle_index_index(),
            this.get_field_1(),
            this.get_field_2(),
            this.get_field_3(),
            this.get_field_4(),
            this.get_field_8());
    }
}

// 0x9f
class OperationStartSeaBattle {
    OperationStartSeaBattle(address) {
        this.address = address;
    }

    get_battle_index() {
        return Dword(this.address + 0x00);
    }

    get_unknown() {
        return Dword(this.address + 0x04);
    }

    to_string() {
        return form(
            "OperationStartSeaBattle(address=%x, battle_index=0x%x, unknown=0x%x)",
            this.address,
            this.get_battle_index(),
            this.get_unknown());
    }
}

// Unknown
class OperationUnknown {
    OperationUnknown(address, opcode) {
        this.address = address;
        this.opcode = opcode;
    }
    to_string() {
        return form(
            "OperationUnknown(address=0x%x, opcode=0x%x)",
            this.address,
            this.opcode);
    }
}

class Operation {
    Operation(address) {
        this.address = address;
    }
    opcode() {
        return Dword(this.address);
    }
    arg1() {
        return Dword(this.address + 0x04);
    }
    arg2() {
        return Dword(this.address + 0x08);
    }
    arg3() {
        return Dword(this.address + 0x0C);
    }
    arg4() {
        return Dword(this.address + 0x10);
    }
    data() {
        auto opcode = this.opcode();
        if (opcode == 0x00) {
            return OperationSetShipDestination(this.address + 0x04);
        } else if (opcode == 0x0d) {
            return OperationTogglePiracy(this.address + 0x04);
        } else if (opcode == 0x0e) {
            return OperationAttackShip(this.address + 0x04);
        } else if (opcode == 0x61) {
            return OperationAnnounceCelebration(this.address + 0x04);
        } else if (opcode == 0x92) {
            return OperationSeaBattleShipVolley(this.address + 0x04);
        } else if (opcode == 0x9f) {
            return OperationStartSeaBattle(this.address + 0x04);
        } else {
            return OperationUnknown(this.address + 0x04, opcode);
        }
    }
    to_string() {
        return form(
            "Operation(address=0x%x, opcode=0x%02x, data=%s)",
            this.address,
            this.opcode(),
            this.data().to_string());
    }
}
