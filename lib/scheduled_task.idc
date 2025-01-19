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

// 0x01
class ScheduledTaskRepayment {
    ScheduledTaskRepayment(address) {
        this.address = address;
    }

    get_amount() {
        return Dword(this.address + 0x00);
    }

    get_timestamp() {
        return Dword(this.address + 0x04);
    }

    get_timestamp_low() {
        return Byte(this.address + 0x04);
    }

    get_receiving_index() {
        return Byte(this.address + 0x08);
    }

    get_giving_index() {
        return Byte(this.address + 0x09);
    }

    get_is_not_impound() {
        return Byte(this.address + 0x0a);
    }

    get_weeks() {
        return Byte(this.address + 0x0b);
    }

    get_town_index() {
        return Byte(this.address + 0x0c);
    }

    to_string() {
        return form(
            "ScheduledTaskRepayment(address=0x%x, amount=%d, timestamp=0x%x, cannot_pay=0x%x, receiving_index=0x%x, giving_index=0x%x, is_not_impound=0x%x, weeks=%d, town_index=0x%x)",
            this.address,
            this.get_amount(),
            this.get_timestamp(),
            this.get_timestamp_low(),
            this.get_receiving_index(),
            this.get_giving_index(),
            this.get_is_not_impound(),
            this.get_weeks(),
            this.get_town_index());
    }
}

// 0x05
class ScheduledTaskInvestigation {
    ScheduledTaskInvestigation(address) {
        this.address = address;
    }

    get_merchant_index() {
        return Byte(this.address + 0x00);
    }

    get_town_index() {
        return Byte(this.address + 0x01);
    }

    get_hometown_index() {
        return Byte(this.address + 0x03);
    }

    get_crime_type() {
        return Byte(this.address + 0x08);
    }

    get_status() {
        return Byte(this.address + 0x09);
    }

    get_random() {
        return Word(this.address + 0x0a);
    }

    to_string() {
        auto status = this.get_status();
        auto status_string = "";
        if (status == 0) {
            status_string = "Pending";
        } else if (status == 1) {
            status_string = "Investigating";
        } else {
            status_string = form("Unknown (%d)", status);
        }
        
        return form(
            "ScheduledTaskInvestigation(address=%x, merchant_index=0x%x, town_index=0x%x, hometown_index=0x%x, crime_type=0x%x, status=%s)",
            this.address,
            this.get_merchant_index(),
            this.get_town_index(),
            this.get_hometown_index(),
            this.get_crime_type(),
            status_string);
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
        if (opcode == 0x01) {
            return ScheduledTaskRepayment(this.address + 0x08);
        } else if (opcode == 0x05) {
            return ScheduledTaskInvestigation(this.address + 0x08);
        } else if (opcode == 0x32) {
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
