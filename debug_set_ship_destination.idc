#include <idc.idc>
#include "lib/lib.idc"

static handle_op_set_ship_destination() {
    auto ship_index = GetRegValue("eax");
    auto ship = get_ship_by_index(ship_index);
    auto op = OperationSetShipDestination(GetRegValue("edi")+0x04);
    Message(
        "\n\nShip 0x%x (0x%x, 0x%x) -> (0x%x, 0x%x)\n",
        ship_index,
        ship.get_x(),
        ship.get_y(), 
        op.get_x(),
        op.get_y());
}

static handle_op_set_ship_destination_fix() {
    auto ship_index = GetRegValue("eax");
    auto ship = get_ship_by_index(ship_index);
    auto op = OperationSetShipDestination(GetRegValue("edi")+0x04);

    // Patch source
    patch_dbg_dword(ship.address + 0x1c, 0x6e97fff);
    patch_dbg_dword(ship.address + 0x20, 0x2567fff);

    // Patch destination
    patch_dbg_dword(op.address + 0x08, 0x70a);
    patch_dbg_dword(op.address + 0x0c, 0x1b1);

    handle_op_set_ship_destination();
}

static handle_calculate_ship_path() {
    Message("handle_calculate_ship_path found starting navpoint\n");
}

static handle_calculate_ship_path_find_matrix_path() {
    auto eax = GetRegValue("eax");
    auto ship_nav_path = ShipNavPath(eax);
    Message("matrix path: %s\n", ship_nav_path.to_string());
}

static handle_calculate_ship_path_first_point() {
    auto edx = GetRegValue("edx");
    auto x = Word(GetRegValue("eax") + 4 * edx);
    auto y = Word(GetRegValue("eax") + 4 * edx + 2);
    Message("enqueueing point %02d (0x%04x, 0x%04x) (calculate_ship_path)\n", edx, x, y);
}

static handle_ship_path_enqueue() {
    auto esp = GetRegValue("esp");
    auto a3 = ShortPoint(Dword(esp + 0x10));
    auto a2 = ShortPoint(Dword(esp + 0x0c));
    auto a1 = ShortPoint(Dword(esp + 0x08));
    Message(
        "handle_ship_path_enqueue(%s, %s, %s)\n",
        a1.to_string(),
        a2.to_string(),
        a3.to_string());
}

static handle_ship_path_enqueue_1() {
    auto path_ptr = Dword(GetRegValue("esi"));
    auto old_path_len = GetRegValue("ebx");
    Message(
        "enqueueing point %02d (0x%04x, 0x%04x) (path_enqueue_stuff loc1)\n",
        GetRegValue("ebx"),
        Word(path_ptr + old_path_len * 4),
        Word(path_ptr + old_path_len * 4 + 2));
}

static handle_ship_path_enqueue_2() {
    auto old_path_len = GetRegValue("eax");
    auto path_ptr = Dword(GetRegValue("esi"));
    Message(
        "enqueueing point %02d (0x%04x, 0x%04x) (path_enqueue_stuff loc2)\n",
        old_path_len,
        Word(path_ptr + old_path_len * 4),
        Word(path_ptr + old_path_len * 4 + 2));
}

static handle_ship_path_done() {
    auto path_ptr = Dword(GetRegValue("edi"));
    Message("Finished route 0x%x with %d nodes\n", path_ptr, Dword(path_ptr + 0x04));
}

static handle_calculate_ship_path_find_matrix_path_update_candidate() {
    auto esp = GetRegValue("esp");
    auto calculated_destination_index = GetRegValue("edx");
    auto calculated_source_index = GetRegValue("edi");
    auto distance_old = TO_LONG(Dword(esp + 0x38));
    auto distance_new = TO_LONG(GetRegValue("ecx"));
    auto path_distance_new = GetRegValue("eax");

    Message("%d -> %d (path_distance_new=%d, distance_new=%d)\n",
        calculated_source_index,
        calculated_destination_index,
        path_distance_new,
        distance_old,
        distance_new);
}

static main() {
    AddBpt(0x00537686);
    SetBptCnd(0x00537686, "handle_op_set_ship_destination_fix()");

    AddBpt(0x00445340);
    SetBptCnd(0x00445340, "handle_calculate_ship_path()");

    AddBpt(0x00445340);
    SetBptCnd(0x00445340, "handle_calculate_ship_path_find_matrix_path()");

    AddBpt(0x004453E0);
    SetBptCnd(0x004453E0, "handle_calculate_ship_path_first_point()");

    AddBpt(0x00446F21);
    SetBptCnd(0x00446F21, "handle_ship_path_enqueue()");

    AddBpt(0x00447454);
    SetBptCnd(0x00447454, "handle_ship_path_enqueue_1()");

    AddBpt(0x004474BB);
    SetBptCnd(0x004474BB, "handle_ship_path_enqueue_2()");

    AddBpt(0x0051738B);
    SetBptCnd(0x0051738B, "handle_ship_path_done()");

    AddBpt(0x00444B3B);
    SetBptCnd(0x00444B3B, "handle_calculate_ship_path_find_matrix_path_update_candidate()");
}
