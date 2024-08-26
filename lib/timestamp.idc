#define TICKS_PER_YEAR      93440;
#define TICKS_PER_DAY       00256;

class Timestamp {
    Timestamp(value) {
        this.value = value;
    }

    get_year() {
        return this.value / TICKS_PER_YEAR;
    }

    get_day() {
        return this.value / TICKS_PER_DAY;
    }

    to_string() {
        return sprintf(
            "%d %d",
            this.get_year(),
            this.get_day() % 365);
    }
}

static now() {
    return Timestamp(Dword(GAME_WORLD_PTR + 0x14));
}
