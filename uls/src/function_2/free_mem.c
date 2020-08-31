#include "uls.h"

void mem_free(flags_t *flag) {
    free(flag->all_flags);
    free(flag);
}
