#ifndef NBR_TO_HEX_H
#define NBR_TO_HEX_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

char *mx_strnew(const int size);
char *mx_nbr_to_hex(unsigned long nbr);

#endif
