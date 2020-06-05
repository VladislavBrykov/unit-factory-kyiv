#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

void mx_printchar(char c);
void mx_printint(int n);
int mx_strlen(const char *c);
void mx_printstr(const char *s);
char *mx_strcpy(char *dst, const char *src);
int mx_strcmp(const char *s1, const char *s2);
bool mx_isdigit(int c);
bool mx_isspace(char c);
int mx_atoi(const char *str);

#endif

/*
При кампиляции указываем все используемые функции, 
Можно не прописывать в функциях библиотеки и не обьявлять другие используемые функции
мы их уже прописали в хедере
В каждой используемой функции нужно убрать библиотеки и обьявить хедер

В данном случае конструкция, которая обрамляет весь файл – защита от 
повторного определения функций и прочего при следующем include
*/
