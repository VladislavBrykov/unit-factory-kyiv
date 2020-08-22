#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//Until
int mx_atoi(const char *str);
int mx_insertion_sort(char **arr, int size);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);
void mx_strdel(char **str);
int mx_strlen(const char *s);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);
int mx_is_space(char c);
char *mx_strndup(const char *s1, size_t n);
char *mx_strtrim(const char *str);
void mx_printerr(const char *s);
//Confirmation
bool mx_is_duplicate(const char *argv[]);
bool mx_is_rank(char c);
bool mx_is_suit(char c);
bool mx_is_valid(const char *name[]);
bool mx_is_flush (char *b);
bool mx_is_kare (int *arr);
bool mx_is_set(int *arr);
bool mx_is_street(int *arr);
//Cards
int *mx_to_int(const char *argv[]);
char *mx_to_char(const char *argv[]);
int mx_pairs(int *arr);
void mx_sort (int *c , char *b);
char *mx_result(int *c, char *b);

#endif
