#include <idc.idc>
#include "lib/lib.idc"

static handle_malloc_battle() {
    auto address = GetRegValue("eax");
    auto esi = GetRegValue("esi");
    auto ecx = GetRegValue("ecx");
    auto dest = esi + ecx * 4;
    Message("### Battle 0x%x allocated: *0x%x = 0x%x\n", ecx, dest, address);
    return 0;
}

static handle_init_class55() {
    auto ecx = GetRegValue("ecx");
    Message("### Initializing class55 at 0x%x\n", ecx);
    return 0;
}

static handle_apply_battle_damage() {
    auto esp = GetRegValue("esp");
    auto damage = Dword(esp + 8);
    auto ecx = GetRegValue("ecx");
    auto class55 = Class55(ecx);
    auto ship = get_ship_by_index(class55.get_ship_index());
    Message("### Ship %s taking %d battle damage (class55 at 0x%x)\n", ship.to_string(), damage, ecx);
    return 0;
}

static do_battle_projectile_damage_calcs() {
    auto ecx = GetRegValue("ecx");
    auto class55 = Class55(ecx);

    auto esp = GetRegValue("esp");
    auto x = Word(esp + 0x08);
    auto y = Word(esp + 0x0c);

    Message("### Projectile damage calculations (%d, %d, %s)\n", x, y, class55.to_string());
    return 0;
}

static do_battle_projectile_damage_calcs_distance() {
    auto distance = GetRegValue("eax");
    Message("### distance=%d (0x%x)\n", distance, distance);
    return 0;
}

static do_battle_projectile_damage_calcs_distance_fix() {
    auto new_distance = GetRegValue("ecx");
    Message("### fixed_distance=%d (0x%x)\n", new_distance, new_distance);
    return 0;
}

static battle_projectile_damage_calc() {
    auto esp = GetRegValue("esp");
    auto raw_damage = Dword(esp + 0xc);
    Message("### battle_projectile_damage_calc raw_damage=%d (0x%x)\n", raw_damage, raw_damage);
    return 0;
}

static battle_projectile_damage_calc_angle() {
    auto wind_angle = GetRegValue("eax");
    Message("### wind_angle=%d (0x%x)\n", wind_angle, wind_angle);
    return 0;
}

static handle_init_class66() {
    auto damage = Dword(GetRegValue("esp") + 0x18);
    Message("### Class66(damage=%d (0x%x))\n", damage, damage);
    return 0;
}

static main() {
    Message("\n\n");
    AddBpt(0x00611D57);
    SetBptCnd(0x00611D57, "handle_malloc_battle()");

    AddBpt(0x0061A4E0);
    SetBptCnd(0x0061A4E0, "handle_init_class55()");
    
    AddBpt(0x0061F972);
    SetBptCnd(0x0061F972, "handle_apply_battle_damage()");

    AddBpt(0x0061E8EF);
    SetBptCnd(0x0061E8EF, "do_battle_projectile_damage_calcs()");

    AddBpt(0x0061E941);
    SetBptCnd(0x0061E941, "do_battle_projectile_damage_calcs_distance()");

    AddBpt(0x0061ED2A);
    SetBptCnd(0x0061ED2A, "do_battle_projectile_damage_calcs_distance_fix()");

    AddBpt(0x006214CB);
    SetBptCnd(0x006214CB, "battle_projectile_damage_calc()");

    AddBpt(0x0061ECEA);
    SetBptCnd(0x0061ECEA, "battle_projectile_damage_calc_angle()");
    
    AddBpt(0x00602A90);
    SetBptCnd(0x00602A90, "handle_init_class66()");

    auto battles_allocated = get_battles_allocated();
    Message("Battles allocated: %d\n", battles_allocated);

    auto i;
    for (i = 0; i < battles_allocated; i++) {
        auto battle = get_battle_by_index(i);
        Message("%s\n", battle.to_string());

        auto j;
        for (j = 0; j < battle.get_class55s_len(); j++) {
            auto class55 = battle.get_class55(j);
            Message("  %s\n", class55.to_string());
        }
    }
}
