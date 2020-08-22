#ifndef MX_CAT_H
#define MX_CAT_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int mx_strlen(const char *s);
void mx_printerr(const char *s);
void mx_printchar(char c);
void mx_printstr(const char *s);
void mx_printint(int n);
char *mx_strnew(const int size);

#endif 
