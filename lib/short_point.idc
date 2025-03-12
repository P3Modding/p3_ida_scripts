class ShortPoint {
    ShortPoint(address) {
        this.address = address;
    }

    get_x() {
        return Word(this.address + 0x00);
    }

    get_y() {
        return Word(this.address + 0x02);
    }

    to_string() {
        return sprintf("(0x%x, 0x%x)", this.get_x(), this.get_y());
    }
}
