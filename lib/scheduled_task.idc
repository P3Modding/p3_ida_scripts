// Unknown
class ScheduledTaskUnknown {
    ScheduledTaskUnknown(address, opcode) {
        this.address = address;
        this.opcode = opcode;
    }

    to_string() {
        return form(
            "ScheduledTaskUnknown(address=0x%x, opcode=0x%x)",
            this.address,
            this.opcode);
    }
}

class ScheduledTask {
    ScheduledTask(address) {
        this.address = address;
    }

    get_due_timestamp() {
        return Dword(this.address);
    }

    get_next_task_index() {
        return Word(this.address + 0x04);
    }

    get_opcode() {
        return Word(this.address + 0x06);
    }

    get_data() {
        auto opcode = this.get_opcode();
        if (opcode == 0x32) {
            return AldermanMission(this.address + 0x08);
        } else {
            return ScheduledTaskUnknown(this.address + 0x08, opcode);
        }
    }

    to_string() {
        auto data = this.get_data();
        auto due = this.get_due_timestamp() - get_timestamp();
        return sprintf("ScheduledTask(due_in=0x%04x, data=%s)",
            due,
            data.to_string());
    }
}

static get_task_by_index(index) {
    return ScheduledTask(Dword(SCHEDULED_TASKS_ADDRESS) + 0x18 * index);
}

static get_earliest_task_index() {
    return Word(SCHEDULED_TASKS_ADDRESS + 0x08);
}

static get_tasks_size() {
    return Word(SCHEDULED_TASKS_ADDRESS + 0x0c);
}

