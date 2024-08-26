#include <idc.idc>
#include "lib/lib.idc"

static main() {
    Message("\n\n");

    auto class24 = get_class24();
    Message("%s\n", class24.to_string());
}
