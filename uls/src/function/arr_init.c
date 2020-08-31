#include "uls.h"

//Выделение памяти под двумерный массив
char **arr_init(int argc, int number) {    //выделил память под массив строк файлов для вывода лс
  	char **file_str= malloc(sizeof(char*) * (number + 2)); //number - количество существующих файлов (не директорий)
    	for (int i = 0; i < number; i++)					//их нужно посчитать отдельной функцией
      		file_str[i] = mx_strnew(255);
	file_str[number] = NULL;
return file_str;
}
