#include <idc.idc>
#include "lib/lib.idc"

static handle_operation() {
    auto ptr = GetRegValue("esi");
    auto operation = Operation(ptr);

    // Ignore frequent ops
    if (operation.opcode() == 0x94) {
        return 0; // Tick sea battles
    } else if (operation.opcode() == 0x95) {
        return 0; // Move ship in battle
    } else if (operation.opcode() == 0x71) {
        return 0; // Letter stuff
    } else if (operation.opcode() == 0x7B) {
        return 0; // Update town loans
    }

    Message("Executing %s\n", operation.to_string());
    
    // Return 1 to break on an interesting op
    if (operation.opcode() == 0x00) {
        return 0; // Move ship
    } if (operation.opcode() == 0x02) {
        return 0; // Ship buy wares
    } else if (operation.opcode() == 0x39) {
        return 0; // Bath
    } else if (operation.opcode() == 0x43) {
        return 0; // Bath house bribe
    } else if (operation.opcode() == 0x48) {
        return 0; // Make Town Hall Offer
    } else if (operation.opcode() == 0x61) {
        return 0; // Announce celebration
    } else if (operation.opcode() == 0x6c) {
        return 0;
    } else if (operation.opcode() == 0x92) {
        return 0; // Combat volley
    }
    
    return 0;
}

static handle_insert_operation() {
    auto ptr = GetRegValue("eax");
    auto operation = Operation(ptr);
    
    if (operation.opcode() == 0x00) {
        return 1; // Set Ship Destination
    } else if (operation.opcode() == 0x0d) {
        return 0; // Toggle piracy
    } else if (operation.opcode() == 0x02) {
        return 0; // Ship buy wares
    } else if (operation.opcode() == 0x0e) {
        return 0; // Attack ship
    } else if (operation.opcode() == 0x12) {
        return 0; // Captain experience
    } else if (operation.opcode() == 0x29) {
        return 0; // Grant loan
    } else if (operation.opcode() == 0x2a) {
        return 0; // Repay loan
    } else if (operation.opcode() == 0x43) {
        return 0; // Bribe
    } else if (operation.opcode() == 0x48) {
        return 0; // Make Town Hall Offer
    } else if (operation.opcode() == 0x4b) {
        return 0; // Accept alderman mission
    } else if (operation.opcode() == 0x5b) {
        return 0; // Administrator prices
    } else if (operation.opcode() == 0x61) {
        return 0; // Announce celebration
    } else if (operation.opcode() == 0x7b) {
        return 0; // Update town loans
    } else if (operation.opcode() == 0x77) {
        return 1; // Impound bailing debtor
    } else if (operation.opcode() == 0x92) {
        return 0; // Combat volley
    } else if (operation.opcode() == 0x71) {
        return 0; // Unknown (letter cleanup?)
    } else if (operation.opcode() == 0x9f) {
        return 0; // Start sea battle
    } else if (operation.opcode() == 0xb8) {
        Message("Scheduling operation 0xb8\n");
        return 0; // Thing that enqueues desync check
    } else if (operation.opcode() == 0xd4) {
        Message("Scheduling operation desync check (0xd4)\n");
        // Scheduled once by 0xb8, but is sent twice to clients?!
        return 0; // Desync check
    }
    
    return 0;
}

static main() {
    auto bp = AddBpt(0x0053576B);
    SetBptCnd(0x0053576B, "handle_operation()");
    auto bp2 = AddBpt(0x00543F10);
    SetBptCnd(0x00543F10, "handle_insert_operation()");
}
