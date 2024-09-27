#include <idc.idc>
#include "lib/lib.idc"

static debug_class74(class74) {
    Message("%s\n", class74.to_string());

    if (class74.get_field_94_a4_len() > 0) {
        auto a4_index = 0;
        auto i = 0;
        while (i < class74.get_field_a4_entry(a4_index)) {
            auto screen_rectangle = class74.get_field_a0_entry(i);
            Message("screen_rectangle %d: %s\n",
                i,
                screen_rectangle.to_string());
            
            i = i + 1;

            if (i > 10) {
                Message("aborting enumeration\n");
                break;
            }
        }
    }
}

static main() {
    auto c74;
    Message("\n\n\n");

    auto class73 = get_class73();
    if (class73.address == 0) {
        return;
    }
    Message("Debugging %s\n", class73.to_string());


    c74 = class73.get_();
    Message("\n???:\n");
    debug_class74(c74);
}
