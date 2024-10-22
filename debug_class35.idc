#include <idc.idc>
#include "lib/lib.idc"

static handle_class35_calculate_ship_route_route_allocation() {
    auto eax = GetRegValue("eax");
    Message("Route allocated at 0x%x\n", eax);
}

static handle_class35_calculate_ship_route_points_allocation() {
    auto eax = GetRegValue("eax");
    Message("Points allocated at 0x%x\n", eax);
}

static handle_class35_calculate_ship_route_points_final_allocation() {
    auto eax = GetRegValue("eax");
    Message("Points final allocated at 0x%x\n", eax);
}

static main() {
    AddBpt(0x00445020);
    SetBptCnd(0x00445020, "handle_class35_calculate_ship_route_route_allocation()");
    
    AddBpt(0x0044502C);
    SetBptCnd(0x0044502C, "handle_class35_calculate_ship_route_points_allocation()");

    AddBpt(0x00445D15);
    SetBptCnd(0x00445D15, "handle_class35_calculate_ship_route_points_final_allocation()");
}