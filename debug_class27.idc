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

    auto class27 = get_class27();
    if (class27.address == 0) {
        return;
    }
    Message("Debugging %s\n", class27.to_string());

    auto c74_808 = class27.get_anim2_oben_rechts_alle_res();
    Message("\nanim2 (oben rechts - alle res):\n");
    debug_class74(c74_808);

    c74 = class27.get_anim1_oben_links_800();
    Message("\nanim1 (oben links - 800):\n");
    debug_class74(c74);

    c74 = class27.get_anim41_oben_links_1024();
    Message("\nanim141 (oben links - 1024):\n");
    debug_class74(c74);

    c74 = class27.get_anim42_oben_links_1280();
    Message("\nanim42 (oben links - 1280):\n");
    debug_class74(c74);

    c74 = class27.get_anim4_horizontal_balken_rechts_alle_res();
    Message("\nanim4 (horizontal balken rechts - alle res):\n");
    debug_class74(c74);

    auto c74_c40 = class27.get_anim3_vertikal_balken_rechts_alle_res();
    Message("\nanim3 (vertikal balken rechts - alle res):\n");
    debug_class74(c74_c40);

    c74 = class27.get_anim44_rechts_unten_1024();
    Message("\nanim43 (rechts unten - 1024):\n");
    debug_class74(c74);

    c74 = class27.get_anim44_rechts_unten_1280();
    Message("\nanim44 (rechts unten - 1280):\n");
    debug_class74(c74);

    c74 = class27.get_anim59();
    Message("\nanim59:\n");
    debug_class74(c74);
}
