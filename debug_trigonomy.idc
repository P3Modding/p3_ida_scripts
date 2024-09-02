#include <idc.idc>
#include "lib/lib.idc"

#define COS_TABLE 0x0067B240

static main() {
    auto i;
    while (i != 256) {
        auto val = Dword(COS_TABLE + 4 * i);
        Message("0x%x: %d\n", i, val);
        i = i + 1;
    }

    Message("\n\n");
}
