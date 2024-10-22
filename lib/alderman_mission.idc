class AldermanMissionFoundTown {
    AldermanMissionFoundTown(address) {
        this.address = address;
    }

    get_effective_production() {
        return Dword(this.address);
    }

    get_town_id() {
        return Byte(this.address + 0x04);
    }

    to_string() {
        return sprintf(
            "AldermanMissionFoundTown(address=0x%x, prod=0x%x, town=%s, town_id=0x%x)",
            this.address,
            this.get_effective_production(),
            town_string(this.get_town_id()),
            this.get_town_id());
    }
}

class AldermanMissionOverlandTradeRoute {
    AldermanMissionOverlandTradeRoute(address) {
        this.address = address;
    }

    to_string() {
        return sprintf(
            "AldermanMissionOverlandTradeRoute(address=0x%x)",
            this.address);
    }
}

class AldermanMissionNotoriousPirate {
    AldermanMissionNotoriousPirate(address) {
        this.address = address;
    }

    to_string() {
        return sprintf(
            "AldermanMissionNotoriousPirate(address=0x%x)",
            this.address);
    }
}

class AldermanMissionPirateHideout {
    AldermanMissionPirateHideout(address) {
        this.address = address;
    }

    to_string() {
        return sprintf(
            "AldermanMissionPirateHideout(address=0x%x)",
            this.address);
    }
}

class AldermanMissionSupplyProblems {
    AldermanMissionSupplyProblems(address) {
        this.address = address;
    }

    to_string() {
        return sprintf(
            "AldermanMissionSupplyProblems(address=0x%x)",
            this.address);
    }
}

class AldermanMission {
    AldermanMission(address) {
        this.address = address;
    }

    get_mission_type() {
        return Byte(this.address + 0x04);
    }

    get_merchant_index() {
        return Byte(this.address + 0x05);
    }

    get_reschedule_counter() {
        return Byte(this.address + 0x06);
    }

    get_data() {
        auto mission_type = this.get_mission_type();
        if (mission_type == 0x00) {
            return AldermanMissionFoundTown(this.address + 0x08);
        } else if (mission_type == 0x01) {
            return AldermanMissionOverlandTradeRoute(this.address + 0x08);
        } else if (mission_type == 0x02) {
            return AldermanMissionNotoriousPirate(this.address + 0x08);
        } else if (mission_type == 0x03) {
            return AldermanMissionPirateHideout(this.address + 0x08);
        } else if (mission_type == 0x04) {
            return AldermanMissionSupplyProblems(this.address + 0x08);
        }
    }

    to_string() {
        auto data = this.get_data();
        auto data_string = "Unknown";
        if (data) {
            data_string = data.to_string();
        }
        return sprintf(
            "AldermanMission(address=0x%x, merchant_index=0x%x, reschedule_counter=0x%x, data=%s)",
            this.address,
            this.get_merchant_index(),
            this.get_reschedule_counter(),
            data_string);
    }
}
