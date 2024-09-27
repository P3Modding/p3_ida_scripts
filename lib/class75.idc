class Class75 {
    // Size guessed
    Class75(address) {
        this.address = address;
    }

    get_class77_by_index(index) {
        return Class77(Dword(Dword(this.address + 0x04) + 4 * index));
    }

    get_texture_ids_array() {
        return Dword(this.address + 0x08);
    }

    get_len() {
        return Dword(this.address + 0x10);
    }

    get_rect_indexes_array() {
        return Dword(this.address + 0x9c);
    }

    get_frame_rects_array() {
        return Dword(this.address + 0xa0);
    }

    to_string() {
        return sprintf(
            "Class75(0x%x, len=%d)",
            this.address,
            this.get_len()
        );
    }
}

static get_class75() {
    return Class75(CLASS75_ADDRESS);
}
