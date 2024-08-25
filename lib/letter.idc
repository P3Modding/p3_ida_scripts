#define LETTER_CLASS_MAPPING_PTR    0x006C0198
#define LETTER_TITLES_PTR           0x006A52D0

static get_letter_class_name(class_type) {
    if (class_type == 1) {
        return "Official Writing";
    } else if (class_type == 2) {
        return "Personal Letter";
    } else if (class_type == 3) {
        return "Trading Information";
    } else {
        return "Unknown";
    }
}

static get_letter_class(letter_type) {
    return Byte(LETTER_CLASS_MAPPING_PTR + letter_type);
}

static get_letter_title(letter_type) {
    // TODO: special handling for 60-64
    return get_strlit_contents(Dword(LETTER_TITLES_PTR + 4*letter_type), -1, STRTYPE_C);
}

static debug_letter_type(letter_type) {
    auto letter_class = get_letter_class(letter_type);
    auto letter_title = get_letter_title(letter_type);
    Message("%s: %s\n", get_letter_class_name(letter_class), letter_title);
}

class Letter {
    Letter(address) {
        this.address = address;
    }

    get_type2() {
        return Byte(this.address + 0x04);
    }

    get_town_index() {
        return Byte(this.address + 0x05);
    }

    to_string() {
        return sprintf("Letter()");
    }
}
