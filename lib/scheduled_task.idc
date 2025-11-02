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

// 0x12
class ScheduledTaskExpedition {
    ScheduledTaskExpedition(address) {
        this.address = address;
    }

    get_convoy_index() {
        return Word(this.address + 0x00);
    }

    get_field_2() {
        return Word(this.address + 0x02);
    }

    get_departure_timestamp() {
        return Dword(this.address + 0x04);
    }

    to_string() {
        return sprintf("ScheduledTaskExpedition(address=0x%04x, convoy_index=0x%x, field_2=0x%x, departure_timestamp=0x%x)",
                this.address,
                this.get_convoy_index(),
                this.get_field_2(),
                this.get_departure_timestamp());
    }
}

// 0x2e
class ScheduledTaskCouncilMeeting {
    ScheduledTaskCouncilMeeting(address) {
        this.address = address;
    }

    get_extra_tax_amount() {
        return Dword(this.address + 0x00);
    }

    get_town_index() {
        return Byte(this.address + 0x04);
    }

    get_meeting_type() {
        return Byte(this.address + 0x05);
    }

    get_field_6() {
        return Byte(this.address + 0x06);
    }

    get_votes_remaining() {
        return Byte(this.address + 0x07);
    }

    get_votes_in_favour() {
        return Byte(this.address + 0x08);
    }

    get_votes_against() {
        return Byte(this.address + 0x09);
    }

    get_player_vote_bitmask() {
        return Byte(this.address + 0x0b);
    }

    to_string() {
        return form(
            "ScheduledTaskCouncilMeeting(address=0x%x, meeting_type=%d, pending_yes=0x%x, remaining_no=%d, yes=%d, no=%d, player_bitmap=%b)",
            this.address,
            this.get_meeting_type(),
            this.get_field_6(),
            this.get_votes_remaining(),
            this.get_votes_in_favour(),
            this.get_votes_against(),
            this.get_player_vote_bitmask());
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
        } else if (opcode == 0x12) {
            return ScheduledTaskExpedition(this.address + 0x08);
        } else if (opcode == 0x2e) {
            return ScheduledTaskCouncilMeeting(this.address + 0x08);
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
