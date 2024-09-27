class UIShipyardWindow {
    UIShipyardWindow(address) {
        this.address = address;
    }

    get_x() {
        return Dword(this.address + 0x14);
    }

    get_y() {
        return Dword(this.address + 0x18);
    }

    get_width() {
        return Dword(this.address + 0x2c);
    }

    get_height() {
        return Dword(this.address + 0x30);
    }

    get_selected_page() {
        return TO_LONG(Dword(this.address + 0xc7c));
    }

    to_string() {
        return sprintf(
            "UIShipyardWindow(address=0x%x, page=%d, x=%d, y=%d, width=%d, height=%d)",
            this.address,
            this.get_selected_page(),
            this.get_x(),
            this.get_y(),
            this.get_width(),
            this.get_height()
        );
    }
}

static get_ui_shipyard_window() {
    return UIShipyardWindow(Dword(STATIC_UI_SHIPYARD_WINDOW_PTR_ADDRESS));
}
