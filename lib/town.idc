static get_town_name(town_index) {
    auto address = Dword(TOWN_NAMES_PTR + town_index * 4);
    return get_strlit_contents(address, -1, STRTYPE_C);
}

class Church {
    Church(address) {
        this.address = address;
    }

    get_donations_money() {
        return Dword(this.address);
    }

    to_string() {
        return form(
            "Church(get_donations_money=%u)",
            this.get_donations_money());
    }
}

class Town {
    Town(address) {
        this.address = address;
    }

    get_town_index() {
        return Byte(this.address + 0x02c0);
    }

    get_town_id() {
        return Byte(this.address + 0x02c1);
    }

    get_town_flags() {
        return Dword(this.address + 0x2c8);
    }

    get_citizens_total() {
        return Dword(this.address + 0x2d4);
    }

    get_beggar_flags() {
        return Dword(this.address + 0x76c);
    }

    get_church() {
        return Church(this.address + 0x794);
    }

    get_shipyard_experience() {
        return Dword(this.address + 0x810);
    }

    get_shipyard_something() {
        return float(Dword(this.address + 0x818));
    }

    get_weaponsdealer_merchant() {
        return Byte(this.address + 0x83d);
    }

    get_loan_applicant(index) {
        return LoanApplicant(this.address + 0x9d8 + index * 6);
    }

    to_string() {
        return sprintf(
            "Town(address=0x%08x, name=%s, town_index=0x%x, town_id=0x%x, town_flags=0x%x, citizens_total=%d, beggar_flags=0x%x, church=%s)",
            this.address,
            get_town_name(this.get_town_index()),
            this.get_town_index(),
            this.get_town_id(),
            this.get_town_flags(),
            this.get_citizens_total(),
            this.get_beggar_flags(),
            this.get_church().to_string());
    }
}
