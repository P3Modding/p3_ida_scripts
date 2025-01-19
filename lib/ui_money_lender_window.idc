class UIMoneyLenderWindow {
    UIMoneyLenderWindow(address) {
        this.address = address;
    }

    get_grant_loan(index) {
        return OperationGrantLoan(this.address + 0xf5c + index * 0x10);
    }

    to_string() {
        return sprintf(
            "UIMoneyLenderWindow(address=0x%x)",
            this.address);
    }
}

static get_ui_money_lender_window() {
    return UIMoneyLenderWindow(Dword(UI_MONEY_LENDER_WINDOW_PTR_ADDRESS));
}
