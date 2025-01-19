#include <idc.idc>
#include "lib/lib.idc"

static handle_st_crime_investigation_tick() {
    auto esi = GetRegValue("esi");
    auto task = ScheduledTask(esi);
    Message("handle_st_crime_investigation %s\n", task.get_data().to_string());
    if (task.get_data().get_merchant_index() == 0x24) {
        return 1;
    }
}

static main() {
    AddBpt(0x004E5BBC);
    SetBptCnd(0x004E5BBC, "handle_st_crime_investigation_tick()");
}
