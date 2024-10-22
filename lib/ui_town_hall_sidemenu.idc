class UITownHallSidemenu {
    UITownHallSidemenu(address) {
        this.address = address;
    }

    to_string() {
        return sprintf(
            "UITownHallSidemenu(address=0x%x)",
            this.address);
    }
}

static get_ui_town_hall_sidemenu() {
    return UITownHallSidemenu(Dword(UI_TOWN_HALL_SIDEMENU_PTR_ADDRESS));
}
