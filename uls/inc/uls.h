#ifndef ULS_H
#define ULS_H

#include <dirent.h>
#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

void error_flag(char *argv);
void no_such_directory(char *argv);
void uls(int argc, int i, char **name);
void uls_a(char *argv);

#endif
