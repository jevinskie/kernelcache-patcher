#include "kernelcache-patcher/MachO.hpp"
#include "CommonInternal.hpp"

static int dummy;

void set_dummy(int val) {
    dummy = val;
}

int get_dummy() {
    return dummy;
}
