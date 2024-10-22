class UITownHallWindow {
    UITownHallWindow(address) {
        this.address = address;
    }

    to_string() {
        return sprintf(
            "UITownHallWindow(address=0x%x)",
            this.address);
    }
}

static get_ui_town_hall_window() {
    return UITownHallWindow(Dword(UI_TOWN_HALL_WINDOW_PTR_ADDRESS));
}
