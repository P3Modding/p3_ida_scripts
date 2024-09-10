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

static handle_init_local_map_ship() {
    auto ecx = GetRegValue("ecx");
    Message("### Initializing LocalMapShip at 0x%x\n", ecx);
    return 0;
}

static handle_apply_battle_damage() {
    auto esp = GetRegValue("esp");
    auto damage = Dword(esp + 8);
    auto a4 = Dword(esp + 0x10);
    auto a4_str;
    if (a4 == 0) {
        a4_str = "None";
    } else if (a4 == 1) {
        a4_str = "Left";
    } else if (a4 == 2) {
        a4_str = "Right";
    } else if (a4 == 3) {
        a4_str = "Random";
    }
    auto ecx = GetRegValue("ecx");
    auto local_map_ship = LocalMapShip(ecx);
    auto ship = get_ship_by_index(local_map_ship.get_ship_index());
    Message("### Ship %s taking %d battle damage (LocalMapShip at 0x%x), a4=%d (%s)\n", ship.to_string(), damage, ecx, a4, a4_str);
    return 0;
}

static do_battle_projectile_damage_calcs() {
    auto ecx = GetRegValue("ecx");
    auto local_map_ship = LocalMapShip(ecx);

    auto esp = GetRegValue("esp");
    auto x = Word(esp + 0x08);
    auto y = Word(esp + 0x0c);

    Message("### Projectile damage calculations (%d, %d, %s)\n", x, y, local_map_ship.to_string());
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
    auto target_x = Word(esp + 0x4);
    auto target_y = Word(esp + 0x8);
    auto raw_damage = Dword(esp + 0xc);
    auto starboard = Dword(esp + 0x10);
    auto a6 = Byte(esp + 0x14);
    auto a7 = Byte(esp + 0x18);

    Message(
        "### battle_projectile_damage_calc tx=0x%x, ty=0x%x, raw_damage=%d (0x%x), a6=0x%x, a7=0x%x\n",
        target_x,
        target_y,
        raw_damage,
        raw_damage,
        a6,
        a7);
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

static handle_tick_sea_battle_chunk() {
    auto battle = Battle(GetRegValue("ecx"));
    auto esp = GetRegValue("esp");
    auto a = Dword(esp + 0x04);
    auto b = Dword(esp + 0x08);

    if (!battle.get_field_18_byte(a)) {
        Message(
            "### handle_tick_sea_battle_chunk(battle, a=%02d, b=%02d, f0x18[a] = %d, f0x18[b] = %d)\n",
            a,
            b,
            battle.get_field_18_byte(a),
            battle.get_field_18_byte(b));
    }
    return 0;
}

static handle_get_sea_battle_projectile_impact_direction() {
    Message("######################### get_sea_battle_projectile_impact_direction\n");
    auto battle = Battle(GetRegValue("ecx"));
    auto esp = GetRegValue("esp");
    auto projectile_index = Word(esp + 0x08);
    auto projectile = battle.get_projectile(projectile_index);
    auto local_map_ship_index = Word(esp + 0x0c);
    Message("### %s (projectile_index=%d, local_map_ship_index=%d)\n", projectile.to_string(), projectile_index, local_map_ship_index);
    return 0;
}

static handle_get_sea_battle_projectile_impact_direction_angle() {
    auto ebp = GetRegValue("ebp");
    auto battle = Battle(Dword(ebp + 0x3c - 8));
    auto local_map_ship_index = Dword(ebp + 0xc);
    auto local_map_ship = battle.get_local_map_ship(local_map_ship_index);
    auto direction = local_map_ship.get_field_11_direction();
    auto a = direction * 1.40625;
    auto cos = (0.0 + Dword(ebp - 0x50)) / 65536.0;
    auto sin = (0.0 + Dword(ebp - 0x44)) / 65536.0;
    Message(
        "### local_map_ship_index %d: a=%d° (0x%x), sin(a) = %.2f, cos(a) = %.2f\n",
        local_map_ship_index,
        a,
        direction,
        sin,
        cos);
    return 0;
}

static handle_get_sea_battle_projectile_impact_direction_delta_fix() {
    auto ebp = GetRegValue("ebp");
    auto dx = TO_LONG(Dword(ebp-0x20));
    auto dy = TO_LONG(Dword(ebp-0x34));
    Message(
        "### dx=%d dy=%d\n",
        dx,
        dy);
    return 0;
}

static handle_get_sea_battle_projectile_impact_direction_evaluation() {
    auto hitbox_point = GetRegValue("ecx");
    Message("### hitbox_point %d hit!\n", hitbox_point);
    return 0;
}

static handle_get_sea_battle_projectile_impact_direction_hitbox_vec_loop() {
    auto ebp = GetRegValue("ebp");
    auto x = TO_LONG(Dword(ebp-0x28));
    auto y = TO_LONG(Dword(ebp-0x04));
    auto point = Byte(ebp-0x2d);
    Message("### Hitbox point %d translated to (%d, %d)\n", point, x, y);
    return 0;
}

static main() {
    Message("\n\n");
    AddBpt(0x00611D57);
    SetBptCnd(0x00611D57, "handle_malloc_battle()");

    AddBpt(0x0061A4E0);
    SetBptCnd(0x0061A4E0, "handle_init_local_map_ship()");
    
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

    AddBpt(0x00608850);
    SetBptCnd(0x00608850, "handle_tick_sea_battle_chunk()");

    AddBpt(0x0060A73D);
    SetBptCnd(0x0060A73D, "handle_get_sea_battle_projectile_impact_direction()");

    AddBpt(0x0060A99E);
    SetBptCnd(0x0060A99E, "handle_get_sea_battle_projectile_impact_direction_angle()");

    AddBpt(0x0060AACA);
    SetBptCnd(0x0060AACA, "handle_get_sea_battle_projectile_impact_direction_delta_fix()");

    AddBpt(0x0060AD69);
    SetBptCnd(0x0060AD69, "handle_get_sea_battle_projectile_impact_direction_evaluation()");

    AddBpt(0x0060ACA3);
    SetBptCnd(0x0060ACA3, "handle_get_sea_battle_projectile_impact_direction_hitbox_vec_loop()");
    

    auto battles_allocated = get_battles_allocated();
    Message("Battles allocated: %d\n", battles_allocated);

    auto i;
    auto j;
    auto k;
    for (i = 0; i < battles_allocated; i++) {
        auto battle = get_battle_by_index(i);
        Message("%s\n", battle.to_string());

        for (i = 0; i < battle.get_local_map_ships_len(); i++) {
            auto local_map_ship = battle.get_local_map_ship(i);
            Message("  %s\n", local_map_ship.to_string());
        }

        /*
        f0x18 appears to remain stable.
        f0x48, f0x4c and f0x50 contain a matrix of bits (a x b)
            point to pointer array of length (f0x54 + 31) / 32              [columns?]
            arrays have length f0x54                                        [rows?]
            indexing appears to be inverted
                "j" refers to the position in the data array
                "i" refers to the position in the pointer array
                "a" is "j"
                "b" denotes the used array, and slices the appropriate bit out of the u32
            
        If a bit is set, $voodoo is executed
        If f0x18[a] is set, f0x18[b] decides what happens

        Hypothesis: Matrix tracks things which have to tick
            a and b are indexes of interacting things?
            f0x18 denotes the type? 0 is ship?
        */
        auto mask_part_1;
        auto mask_part_2;
        auto mask;;
        if (battle.get_field_50()) {
            Message("field_50:\n");
            for (i = 0; i < battle.get_field_54(); i++) {
                for (j = 0; j < ceililing_div(battle.get_field_54(), 32); j++) {
                    mask_part_1 = battle.get_field_48_target(j, i);
                    mask_part_2 = battle.get_field_4c_target(j, i);
                    mask = mask_part_1 & mask_part_2;

                    for (k = 0; k < 32; k++) {
                        auto is_set = mask & 1;
                        auto a = i;
                        auto b = j * 32 + k;
                        if (is_set) {
                            if (!battle.get_field_18_byte(a)) {
                                auto i1 = battle.get_field_1c_target(a);
                                Message(
                                    "(a=%02d, b=%02d) *a: %d, *b: %d local_map_ship=%d\n",
                                    a,
                                    b,
                                    battle.get_field_18_byte(a),
                                    battle.get_field_18_byte(b),
                                    i1);
                            }
                        }
                        mask = mask >> 1;
                    }
                }
            }
            Message("\n");
        }
    }
}
