#include <idc.idc>
#include "lib/lib.idc"

static main() {
    auto class48 = get_class48();
    Message("%s\n", class48.to_string());
}
