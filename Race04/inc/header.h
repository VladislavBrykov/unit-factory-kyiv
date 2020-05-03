#ifndef HEADER
#define HEADER

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>

void mx_printint(long n);
void mx_printchar(char c);
int mx_strlen(const char *s);
void mx_printstr(const char *s);
void mx_printerr(const char *s);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
int mx_strcmp( const char *s1, const char *s2);

#endif
