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

// 0x01
class OperationShipSellWares {
    OperationShipSellWares(address) {
        this.address = address;
    }

    get_amount() {
        return Dword(this.address + 0x00);
    }

    get_ware_id() {
        return Word(this.address + 0x04);
    }

    get_ship_index() {
        return Word(this.address + 0x06);
    }

    get_merchant_index() {
        return Word(this.address + 0x08);
    }

    get_town_index() {
        return Word(this.address + 0x0a);
    }

    to_string() {
        return form(
            "OperationShipSellWares(address=%x, amount=%d, ware_id=0x%x, ship_index=0x%x, merchant_index=0x%x, town_index=0x%x)",
            this.address,
            this.get_amount(),
            this.get_ware_id(),
            this.get_ship_index(),
            this.get_merchant_index(),
            this.get_town_index());
    }
}

// 0x02
class OperationShipBuyWares {
    OperationShipBuyWares(address) {
        this.address = address;
    }

    get_amount() {
        return Dword(this.address + 0x00);
    }

    get_ware_id() {
        return Word(this.address + 0x04);
    }

    get_ship_index() {
        return Word(this.address + 0x06);
    }

    get_merchant_index() {
        return Word(this.address + 0x08);
    }

    get_town_index() {
        return Word(this.address + 0x0a);
    }

    to_string() {
        return form(
            "OperationShipBuyWares(address=%x, amount=%d, ware_id=0x%x, ship_index=0x%x, merchant_index=0x%x, town_index=0x%x)",
            this.address,
            this.get_amount(),
            this.get_ware_id(),
            this.get_ship_index(),
            this.get_merchant_index(),
            this.get_town_index());
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

// 0x26
class OperationDemolishBuilding {
    OperationDemolishBuilding(address) {
        this.address = address;
    }

    get_town_index() {
        return Dword(this.address + 0x00);
    }

    get_merchant_index() {
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
            "OperationDemolishBuilding(address=%x, town_index=0x%x, merchant_index=0x%x, x=0x%x, y=0x%x)",
            this.address,
            this.get_town_index(),
            this.get_merchant_index(),
            this.get_x(),
            this.get_y());
    }
}

// 0x29
class OperationGrantLoan {
    OperationGrantLoan(address) {
        this.address = address;
    }

    get_repay_amount() {
        return Dword(this.address + 0x00);
    }

    get_interest_rate() {
        return Byte(this.address + 0x04);
    }

    get_rank() {
        return Byte(this.address + 0x05);
    }

    get_amount() {
        return Word(this.address + 0x08);
    }

    get_weeks() {
        return Byte(this.address + 0x0a);
    }

    get_loan_result() {
        return Byte(this.address + 0x0b);
    }

    get_giving_merchant_index() {
        return Byte(this.address + 0x0c);
    }

    get_receiving_merchant_index() {
        return Byte(this.address + 0x0d);
    }

    get_town_index() {
        return Byte(this.address + 0x0e);
    }

    get_wtf() {
        return Byte(this.address + 0x0f);
    }

    to_string() {
        return form(
            "OperationGrantLoan(address=0x%x, repay_amount=%d, interest_rate=%d, rank=%d, amount=%d, weeks=%d, loan_result=0x%x, giving_merchant_index=0x%x, receiving_merchant_index=0x%x, town_index=0x%x, wtf=0x%x)",
            this.address,
            this.get_repay_amount(),
            this.get_interest_rate(),
            this.get_rank(),
            this.get_amount(),
            this.get_weeks(),
            this.get_loan_result(),
            this.get_giving_merchant_index(),
            this.get_receiving_merchant_index(),
            this.get_town_index(),
            this.get_wtf());
    }
}

// 0x48
class OperationMakeTownHallOffer {
    OperationMakeTownHallOffer(address) {
        this.address = address;
    }

    get_meeting_timestamp() {
        return Dword(this.address + 0x00);
    }

    get_town_index() {
        return Byte(this.address + 0x08);
    }

    get_meeting_type() {
        return Byte(this.address + 0x09);
    }

    to_string() {
        return form(
            "OperationMakeTownHallOffer(address=%x, meeting_timestamp=0x%x, town_index=0x%x, meeting_type=%d)",
            this.address,
            this.get_meeting_timestamp(),
            this.get_town_index(),
            this.get_meeting_type());
    }
}

// 0x52
class OperationTavernInteraction {
    OperationTavernInteraction(address) {
        this.address = address;
    }

    get_rand() {
        return Dword(this.address + 0x00);
    }

    get_merchant_index() {
        return Dword(this.address + 0x04);
    }

    get_town_index() {
        return Dword(this.address + 0x08);
    }

    get_interaction_type() {
        return Dword(this.address + 0x0c);
    }

    to_string() {
        auto details = "";
        auto merchant_index = this.get_merchant_index();
        auto town_index = this.get_town_index();
        auto rand = this.get_rand();
        auto town = get_town_by_index(town_index);
        auto weaponsdealer_merchant = town.get_weaponsdealer_merchant();
        auto interaction_type = this.get_interaction_type();

        if (interaction_type == 6 && merchant_index >= 0x24 && weaponsdealer_merchant == 0xff) {
            auto failed_check = (rand & 0x3ff) < 102;
            details = form(", is_illegal=true, failed_check=%d", failed_check);
        }

        return form(
            "OperationTavernInteraction(address=%x, rand=%d, merchant_index=0x%x, town_index=0x%x, interaction_type=%d%s)",
            this.address,
            rand,
            merchant_index,
            town_index,
            this.get_interaction_type(),
            details);
    }
}

// 0x5b
class OperationOfficeAutotradeChangeSetting {
    OperationOfficeAutotradeChangeSetting(address) {
        this.address = address;
    }

    get_stock() {
        return Dword(this.address + 0x00);
    }

    get_price() {
        return TO_LONG(Dword(this.address + 0x04));
    }

    get_office_index() {
        return TO_LONG(Dword(this.address + 0x08));
    }

    get_ware_id() {
        return TO_LONG(Dword(this.address + 0x0c));
    }

    to_string() {
        return form(
            "OperationOfficeAutotradeChangeSetting(address=%x, stock=%d, price=%d, office_index=%d, ware=%s)",
            this.address,
            this.get_stock(),
            this.get_price(),
            this.get_office_index(),
            ware_string(this.get_ware_id()));
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

// 0x66
class OperationOfficeAutotradeLock {
    OperationOfficeAutotradeLock(address) {
        this.address = address;
    }

    get_ware_id() {
        return Dword(this.address + 0x00);
    }

    get_merchant_index() {
        return Dword(this.address + 0x04);
    }

    get_town_index() {
        return Dword(this.address + 0x08);
    }

    get_lock() {
        return Dword(this.address + 0x0c);
    }

    to_string() {
        return form(
            "OperationOfficeAutotradeLock(address=0x%x, ware=%s, merchant_index=0x%x, town_index=0x%x, lock=%d)",
            this.address,
            ware_string(this.get_ware_id()),
            this.get_merchant_index(),
            this.get_town_index(),
            this.get_lock());
    }
}

// 0x6c
class OperationAudotradeRouteCreateOrLoad {
    OperationAudotradeRouteCreateOrLoad(address) {
        this.address = address;
    }

    get_ship_index() {
        return Dword(this.address + 0x00);
    }

    get_town_index() {
        return Dword(this.address + 0x04);
    }

    get_stops_count() {
        return Dword(this.address + 0x08);
    }

    to_string() {
        return form(
            "OperationAudotradeRouteCreateOrLoad(address=0x%x, ship_index=0x%x, town_index=0x%x, stops_count=0x%x)",
            this.address,
            this.get_ship_index(),
            this.get_town_index(),
            this.get_stops_count());
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
        } else if (opcode == 0x01) {
            return OperationShipSellWares(this.address + 0x04);
        } else if (opcode == 0x02) {
            return OperationShipBuyWares(this.address + 0x04);
        } else if (opcode == 0x0d) {
            return OperationTogglePiracy(this.address + 0x04);
        } else if (opcode == 0x0e) {
            return OperationAttackShip(this.address + 0x04);
        } else if (opcode == 0x26) {
            return OperationDemolishBuilding(this.address + 0x04);
        } else if (opcode == 0x29) {
            return OperationGrantLoan(this.address + 0x04);
        } else if (opcode == 0x48) {
            return OperationMakeTownHallOffer(this.address + 0x04);
        } else if (opcode == 0x52) {
            return OperationTavernInteraction(this.address + 0x04);
        } else if (opcode == 0x5b) {
            return OperationOfficeAutotradeChangeSetting(this.address + 0x04);
        } else if (opcode == 0x61) {
            return OperationAnnounceCelebration(this.address + 0x04);
        } else if (opcode == 0x66) {
            return OperationOfficeAutotradeLock(this.address + 0x04);
        } else if (opcode == 0x6c) {
            return OperationAudotradeRouteCreateOrLoad(this.address + 0x04);
        } else if (opcode == 0x85) {
            return AldermanMission(this.address + 0x04);
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
