#include <idc.idc>
#include "lib/lib.idc"

static debug_bremen_loans() {
    auto i;
    auto bremen = get_town_by_index(0x06);
    Message("%s\n", bremen.to_string());
    for (i=0; i<6; i++) {
        auto applicant = bremen.get_loan_applicant(i);
        Message("    %s\n", applicant.to_string());
    }

    Message("Window:\n");
    auto window = get_ui_money_lender_window();
    for (i=0; i<window.get_next_loan_index(); i++) {
        auto loan = window.get_grant_loan(i);
        Message("    %s\n", loan.to_string());
    }
}

static main() {
    debug_bremen_loans();
}
