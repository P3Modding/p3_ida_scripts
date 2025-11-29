static get_town_by_index(town_index) {
    return Town(Dword(GAME_WORLD_PTR + 0x68) + 0x9F8 * town_index);
}

static get_day_of_year() {
    return Word(GAME_WORLD_PTR + 0x0004);
}

static get_timestamp() {
    return Dword(GAME_WORLD_PTR + 0x14);
}

class GameWorld {
    GameWorld() {
        this.address = GAME_WORLD_PTR;
    }

    get_merchant_facilities_array() {
        return Dword(this.address + 0x70);
    }

    get_merchant_facility(index) {
        return MerchantFacility(this.get_merchant_facilities_array() + 0x14 * index);
    }

    get_office(index) {
        return Office(Dword(this.address + 0x74) + 0x44C * index);
    }

    get_merchant(index) {
        return Merchant(Dword(this.address + 0x78) + 0x650 * index);
    }

    get_office_of_merchant(merchant_index) {
        auto merchant = this.get_merchant(merchant_index);
        return this.get_office(merchant.first_office_index());
    }
}
