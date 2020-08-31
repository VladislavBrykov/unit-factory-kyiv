#include "uls.h"

static void flag_activator(flags_t *flag, char fl) {
    switch (fl) {
        case 'A': if (flag->a != true && flag->a != true) flag->A = true; break;
        case 'F': flag->F = true; break;
        case 'S': flag->S = true; break;
        case 'a': if (flag->d != true) {flag->a = true; flag->A = false;} break;
        case 'd': flag->d = true; flag->a = false; flag->A = false; break;
        case 'g': flag->g = true; flag->m = false; flag->one = false; break;
        case 'h': flag->h = true; break;
        case 'i': flag->i = true; break;
        case 'l': flag->l = true; flag->m = false; flag->one = false; break;
        case 'n': flag->n = true; flag->m = false; flag->one = false; break;
        case 'm': flag->m = true; flag->l = false; flag->g = false; flag->o = false; flag->n = false; flag->one = false; break;
        case 'o': flag->o = true; flag->m = false; flag->one = false; break;
        case 'p': flag->p = true; break;
        case 'r': flag->r = true; break;
        case 's': flag->s = true; break;
        case 't': flag->t = true; break;
        case '1': flag->one = true; flag->l = false; flag->g = false; flag->o = false; flag->n = false; flag->m = false; break;
    }
}

static void flag_argv_aparter(char *argument , flags_t *flag) {
    bool is_legal;
    int arg_len = mx_strlen(argument);

    if (arg_len > 2 && argument[1] == '-')
        err_ill_option('-', flag);
    if (arg_len == 2 && argument[1] == '-')
        return;
    for (int i = 1; argument[i] != '\0'; i++) {
        is_legal = false;
        for (int j = 0; flag->all_flags[j] != '\0'; j++)
            if (argument[i] == flag->all_flags[j]) {
                is_legal = true;
                flag_activator(flag, argument[i]);
                break;
            }
        if (!is_legal)
            err_ill_option(argument[i], flag);
    }
}

void flag_detector(int count_flags , int argc, char **argv, flags_t *flag) {
    for (int i = 1; i <= count_flags; i++)
        flag_argv_aparter(argv[i], flag);
}
