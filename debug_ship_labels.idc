#include <idc.idc>
#include "lib/lib.idc"

class ShipLabelInner {
    ShipLabelInner(address) {
        this.address = address;
        if (Dword(this.address) != 0x006758F8) {
            Message("WARNING: ShipLabelInner with unexpected vtable!\n");
        }
    }

    get_x() {
        return Dword(this.address + 0x0C) >> 16;
    }

    get_y() {
        return Dword(this.address + 0x10 >> 16);
    }

    get_color2() {
        return Dword(this.address + 0x30);
    }

    get_dx() {
        return Dword(this.address + 0x38);
    }

    get_dy() {
        return Dword(this.address + 0x3c);
    }

    to_string() {
        return sprintf(
            "ShipLabelInner(x=%d, (0x%x), 12=%d, (0x%x), color=0x%08x, dx=%d, dy=%d)",
            this.get_x(),
            this.get_x(),
            this.get_y(),
            this.get_y(),
            this.get_color2(),
            this.get_dx(),
            this.get_dy()
            );
    }
}

// aka class67, from LocalMapShip
class ShipLabel {
    ShipLabel(address) {
        this.address = address;
        if (Dword(this.address) != 0x00675948) {
            Message("WARNING: ShipLabel with unexpected vtable!\n");
        }
    }

    get_vtable() {
        return Dword(this.address);
    }

    get_inner() {
        return ShipLabelInner(this.address + 0x04);
    }

    get_next_address() {
        return Dword(this.address + 0x30);
    }

    to_string() {
        return sprintf(
            "ShipLabel(address=0x%x, vtable=0x%x, inner=%s)",
            this.address,
            this.get_vtable(),
            this.get_inner().to_string());
    }
}



static debug_ship_labels() {
    auto address = Dword(0x006E2D50);
    auto ship_label;
    auto labels_count = 0;
    while (address && labels_count < 10) {
        ship_label = ShipLabel(address);
        address = ship_label.get_next_address();
        Message("%s\n", ship_label.to_string());
        labels_count = labels_count + 1;
    }
}

static main() {}
