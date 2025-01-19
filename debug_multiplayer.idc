#include <idc.idc>
#include "lib/lib.idc"

static handle_operations_mp_recv_lobby_info_buf() {
    auto addr = GetRegValue("esi");
    Message("lobby info recv buf at 0x%x ops array at 0x%x\n", addr-0x10, addr);
}

static handle_operations_mp_send_lobby_info_buf() {
    auto addr = GetRegValue("esi");
    Message("lobby info send buf at 0x%x ops array at 0x%x\n", addr-0x10, addr);
}

static handle_pending_operations_array_pos_write() {
    auto eip = GetRegValue("eip");
    Message("Pending Ops changed, eip=0x%x\n", eip);
}

static handle_class87_copy_from() {
    auto operations = Operations();
    auto pending = operations.get_pending_ops_count();
    auto i;
    for (i = 0; i < pending; i++) {
        auto operation = operations.get_pending_op(i);
        auto opcode = operation.opcode();
        if (opcode != 0x94 && opcode != 0xc4) {
            Message("Moving local op %s to class87\n", operation.to_string());
        }
    }
}

static main() {
    //AddBpt(0x0054B683);
    //SetBptCnd(0x0054B683, "handle_operations_mp_recv_lobby_info_buf()");

    //AddBpt(0x0054BF96);
    //SetBptCnd(0x0054BF96, "handle_operations_mp_send_lobby_info_buf()");

    AddBptEx(0x6DF346, 2, BPT_WRITE);
    SetBptCnd(0x6DF346, "handle_pending_operations_array_pos_write()");

    //AddBpt(0x0054B93C);
    //SetBptCnd(0x0054B93C, "handle_class87_copy_from()");

    Message("\n");
    auto operations = Operations();
    Message("%s\n", operations.to_string());

    // Debug Class85
    auto class85 = operations.get_class85();
    Message("%s\n", class85.to_string());

    // Debug Network_Connects
    auto i;
    for (i = 0; i < 8; i++) {
        auto class84 = operations.get_class84(i);
        Message("%s\n", class84.to_string());
    }
}
