#ifndef FILE_TO_STR_H
#define FILE_TO_STR_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char *mx_strcat(char *s1, const char *s2);
char *mx_strcpy( char *dst, const char *src);
char *mx_strdup(const char *str);
int mx_strlen(const char *s);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strnew(const int size);

#endif
