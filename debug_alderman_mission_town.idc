#include <idc.idc>
#include "lib/lib.idc"

static handle_alderman_mission_town_data() {
    auto esp = GetRegValue("esp");
    auto consumptions = esp + 0x50;
    auto wares = esp + 0xa0;
    auto str = "Ware       Consumption Stock   Ratio\n";
    auto i;
    for (i = 0; i < 20; i++) {
        auto consumption = Dword(consumptions + 4*i);
        if (consumption > 1024) {
            auto stock = Dword(wares + 4*i);
            auto ratio = stock / (consumption >> 10);
            str = str + sprintf("%-10s %d\t%d\t%d\n", ware_string(i), consumption, stock, ratio);
        }
    }
    Message("%s\n", str);
}

static handle_alderman_mission_town_wares() {
    auto esp = GetRegValue("esp");
    auto wares = esp + 0x34;
    auto str = "Wares:\n";
    auto i;
    for (i = 0; i < 4; i++) {
        str = str + sprintf("%s\n", ware_string(Dword(wares + 4*i)));
    }
    Message("%s\n", str);
}

static handle_alderman_mission_town_init_facilities_effective() {
    auto facility_bit = GetRegValue("edi");
    auto bit = 1;
    auto i;
    for (i=0; i < 17; i++) {
        auto shifted = bit << i;
        if (shifted == facility_bit) {
            Message("Effective %s\n", facility_string(i + 4));
        }
    }
}

static handle_prep_alderman_mission_town_matches() {
    auto town_id_equal = GetRegValue("zf");
    auto task = ScheduledTask(GetRegValue("eax"));
    auto operation = Operation(GetRegValue("esi"));
    if (town_id_equal) {
        Message("Prepare mission: Not updating (town matches). Task: %s Operation: %s\n", task.get_data().get_data().to_string(), operation.to_string());
        return 0;
    }
}

static handle_accept_alderman_mission_by_task_index() {
    auto esp = GetRegValue("esp");
    auto task_index = Dword(esp + 0x48);
    auto task = get_task_by_index(task_index);
    Message("Accepting alderman mission %s\n", task.to_string());
}

static main() {
    AddBpt(0x00532F84);
    SetBptCnd(0x00532F84, "handle_alderman_mission_town_data()");

    AddBpt(0x00532FD2);
    SetBptCnd(0x00532FD2, "handle_alderman_mission_town_wares()");

    AddBpt(0x0054591C);
    SetBptCnd(0x0054591C, "handle_alderman_mission_town_init_facilities_effective()");

    AddBpt(0x0053FD71);
    SetBptCnd(0x0053FD71, "handle_prep_alderman_mission_town_matches()");

    AddBpt(0x004EBFD0);
    SetBptCnd(0x004EBFD0, "handle_accept_alderman_mission_by_task_index()");
}
