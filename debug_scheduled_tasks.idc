#include <idc.idc>
#include "lib/lib.idc"

static handle_scheduled_task() {
    auto edi = GetRegValue("edi");
    auto task = ScheduledTask(edi);

    // Ignore requent tasks
    if (task.get_opcode() == 0x00) {
        return 0;
    } else if (task.get_opcode() == 0x04) {
        return 0;
    } else if (task.get_opcode() == 0x0d) {
        return 0;
    } else if (task.get_opcode() == 0x19) {
        return 0;
    } else if (task.get_opcode() == 0x1a) {
        return 0;
    } else if (task.get_opcode() == 0x1b) {
        return 0;
    } else if (task.get_opcode() == 0x25) {
        return 0;
    } else if (task.get_opcode() == 0x26) {
        return 0;
    }

    Message("handle_scheduled_task %s\n", task.to_string());

    if (task.get_opcode() == 0x01) {
        if (task.get_data().get_receiving_index() == 0x24) {
            return 1; // Repayment to player
        }
    } else if (task.get_opcode() == 0x12) {
        return 1; // Expedition
    }
}

static handle_schedule_task() {
    auto ptr = GetRegValue("eax");
    auto opcode_addr = ptr + 6;

    auto mem_bp = AddBptEx(opcode_addr, 2, BPT_WRITE);
    SetBptCnd(opcode_addr, sprintf("handle_st_opcode_set(0x%x)", opcode_addr));

    return 0;
}

static handle_st_opcode_set(address) {
    DelBpt(address);
    auto opcode = Word(address);
    auto eip = GetRegValue("eip");
    auto func_name = get_func_name(eip);
    Message("Instruction at 0x%x (%s) set scheduled task opcode 0x%x\n", eip, func_name, opcode);

    if (opcode == 0x29) {
        return 1; // Captain spawn?
    }

    return 0;
}

static handle_reschedule_task() {
    auto ebx = GetRegValue("ebx");
    auto task = ScheduledTask(ebx);
    if (task.get_opcode() == 0x1b) {
        return 0;
    }
    Message("Rescheduling %s\n", task.to_string());
    if (task.get_opcode() == 0x5) {
        return 0; // Criminal Investigation
    }
}

static debug_tasks() {
    auto size = get_tasks_size();
    auto task_index = get_earliest_task_index();
    while (task_index < size) {
        auto task = get_task_by_index(task_index);
        if (task.get_opcode() == 0x32) {
            Message("%s\n", task.to_string());
        } else if (task.get_opcode() == 0x1) {
            Message("%s\n", task.to_string());
        }
        task_index = task.get_next_task_index();
    }
    Message("\n");
}

static main() {
    AddBpt(0x004D85FC);
    SetBptCnd(0x004D85FC, "handle_scheduled_task()");

    //AddBpt(0x004D8DA3);
    //SetBptCnd(0x004D8DA3, "handle_schedule_task()");

    //AddBpt(0x004D8DE7);
    //SetBptCnd(0x004D8DE7, "handle_reschedule_task()");
}
