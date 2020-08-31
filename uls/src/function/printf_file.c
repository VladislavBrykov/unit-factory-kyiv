#include "uls.h"

void printf_file_directory(char **name, int argc) {

//printf("argc %d\n", argc);

	argc = argc-1;
	char **array = no_such_directory(name, argc);
	int i = size_consol();  //ширина консоли

	// while(i%8 != 0)
	// 	i--;

	//printf("size_consol    %d\n", i);

struct dirent *directory;
	//int z = in_data.max_long; //максимальная длина строки
	//printf("max long    %d\n", z);
	int coount_file = count_file(name, argc); //кол текстовых файлов
	int max_long = 0;
	//printf("count file    %d\n", coount_file);
	int num = 0;
	
	//printf("point           %d\n", point);

	int num_arr = 1;        //рассматривает с первого елемента
	
		while(array[num_arr] != NULL) { 
		if(mx_strlen(array[num_arr]) > num_arr) 
			max_long = mx_strlen(array[num_arr]);
		num_arr++;
	}  //высчитываю длину самого длинного елемента в двумерном массиве
		while((max_long % 8) != 0)
			max_long++;
	int point = ((max_long*argc));  //моя длина всех строк сумарно
	//printf("point_1   %d\n", point);


//printf("max_long      %d\n", max_long);
	//int hhtt = 0;
	// while(hhtt < i) {
	// 	max_long = 
	// }

	// while(((num*num) != coount_file) && (num < coount_file))
	// 	num++;
	/////////////////////////////////////////////////////////////////////////////////////////////
	//если помещается в одну строку с учетом пробелов(кол файлов)
	if(point <= i) {
		while(array[num] != NULL) {
		mx_printstr(array[num]);
		num++;
	}
	mx_printstr("\n");
	num = 0;
	}


	int del = 0;
///////////////////////////////////////////////////////

	if (point > i) {
		//printf("oxyel\n");
int max = i/max_long;

//printf("max %d\n", max);


// while ((argc % max) != 0)
// 	argc++;

//printf("argc     %d\n", argc);
//del = argc/max;

while(argc >=0) {
argc = argc-max;
del++;
}
//printf("del %d\n", del);


///////////////////////////////////////////////////////		
		//while((point % del != 0) && (del <= coount_file))
			//del++;  //количество строк которое нужно будет вывести
		//printf("kol strok %d\n", del);
		int sgag = coount_file/del;  // =5
		int resurs = 0;
		int ss = 0;
		while(resurs < del) {
			num = resurs;
			while(num < coount_file) {
				mx_printstr(array[num]);
				//printf(" ");
				num = num + del;
				ss++;
			}
			mx_printstr("\n");
			//mx_printstr("\n");
			resurs++;
			num = 0;
		}
	} 
	///////////////////////////////////////////////////////////////////////////////////////////
	//если куб - не работает


}
