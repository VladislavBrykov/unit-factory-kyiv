#include "uls.h"

void flags_init(flags_t *flag) {
    flag->all_flags = mx_strnew(17);
    flag->all_flags = mx_strcpy(flag->all_flags, "AFSadghilnmoprst1");
    flag->A = false;
    flag->F = false;
    flag->S = false;
    flag->a = false;
    flag->d = false;
    flag->g = false;
    flag->h = false;
    flag->i = false;
    flag->l = false;
    flag->n = false;
    flag->m = false;
    flag->o = false;
    flag->r = false;
    flag->s = false;
    flag->t = false;
    flag->one = false;
}
