#include "uls.h"

void printf_directory(int argc, int signal) {

int kaka = 1;

while(kaka < argc) {
	char **array = in_data.str_directory[kaka];
////////////////////////////////////////////
	int i = size_consol();  //ширина консоли
	//printf("size_consol                     %d\n", i);

	int max_long = 0;       //максимальная длина строки
	int num_arr = 1;        //рассматривает с первого елемента
	max_long = mx_strlen(array[num_arr]);  //высчитываю длину самого длинного елемента в двумерном массиве


	while(array[num_arr] != NULL) { 
		if(mx_strlen(array[num_arr]) > max_long) 
			max_long = mx_strlen(array[num_arr]);
		num_arr++;
	}
	//printf("max_long  %d\n", max_long); 

	///////////////////////////////////////////////
	int count_directory = 0;
	int ddd = 1;
	int count = 1;
	int stroka = 1;

	while (array[ddd] != NULL) {
		//mx_printstr(array[ddd]);
		//mx_printstr("\n");
		if(!mx_isspace(array[ddd][0]))
			count++;
		ddd++;
	}
	
	count = count - 1;        //кол текстовых файлов
	//printf("%d\n", count);
///////////////////////////////////////////////////
while((max_long % 8) != 0)    //максимально длинный элемент строки округляю до числа кратного 8
	max_long++;

//printf("max_long                    %d\n", max_long);

	int point = ((max_long*count) + count); //моя длина всех строк сумарно
	
	//printf("count  %d\n", count); 
		//printf("point           %d\n", point);

//////////////////////////////////////////

int num = 1;
int zz =0;


/********************************************************************************************************/

if(point <= i) {
	while(array[0][zz] != '\t')
		zz++;

	if((argc > 2) || (signal > 1)) {
		//printf("argc   %d\n", argc);
		//printf("signal   %d\n", signal);
	array[0][zz] = ':';
	array[0][zz+1] = '\0';
	}

	if(kaka > 1) 
	mx_printstr("\n");
	
	if((argc > 2) || (signal > 1)) {
	mx_printstr(array[0]);
	mx_printstr("\n");
	}
		while(array[num] != NULL) {
		mx_printstr(array[num]);
		//mx_printstr(" ");
		num++;
	}
	mx_printstr("\n");
	num = 0;
	}

///////////////////////////////////////////////////
 	int del = 0;

/*******************************************************************************************************/
	if (point > i) {
		if(kaka > 1) 
			mx_printstr("\n");
zz = 0;
while(array[0][zz] != '\t')
		zz++;
	array[0][zz] = ':';
	array[0][zz+1] = '\0';
	mx_printstr(array[0]);
	mx_printstr("\n");
	//работает
///////////////////////////////////////

/*while(point % i !=0)   // i ширина консоли
	point++;          //моя длина всех строк сумарно

del = point/i;   //количество строк которое нужно будет вывести
printf("kol strok                      %d\n", del);
*/

while((max_long % 8) != 0)
	max_long++;


int max = i/max_long;

while ((count % max) != 0)
	count++;

del = count/max;
// printf("count lines               %d\n", del);
// printf("count           %d\n", count);
// printf("i           %d\n", i);
// printf("max_long           %d\n", max_long);
// int rev = count; //кол текстовых файлов
//printf("count file                          %d\n", rev);

/*while((rev % del) != 0)
	rev++;

if(((rev /del) * max_long) > i)
	del++;
	*/
//////////////////////////////////////////////************************************************************
// int del_new = (count/del)* max_long + 8;
// while((rev % del) != 0)
// 	rev++;

// if(((rev /del) * max_long) > i)
// 	del++;

// del = del
/////////////////////////////////////////
		//while((point % del != 0) && (del <= coount_file))
			//del++;  //количество строк которое нужно будет вывести
		//printf("kol strok %d\n", del);
		int resurs = 1;
		int ss = 0;
		while(resurs <= del) {
			num = resurs;
			while(num <= count) {
				mx_printstr(array[num]);
				//printf(" ");
				num = num + del;
				ss++;
			}
			mx_printstr("\n");
			resurs++;
			num = 0;
		}
	}
/////////////////////////////////////
	kaka++;
}
}



// 	char **array = no_such_directory(name, argc);

// 	int i = size_consol();  //ширина консоли
// 	//printf("size_consol    %d\n", i);

// 	int z = in_data.max_long; //максимальная длина строки
// 	//printf("max long    %d\n", z);

// 	int coount_file = count_file(name, argc); //кол текстовых файлов
// 	//printf("count file    %d\n", coount_file);

// 	int num = 0;

// 	int point = ((z*coount_file) + coount_file);  //моя длина всех строк сумарно
// 	//printf("point           %d\n", point);

// 	// while(((num*num) != coount_file) && (num < coount_file))
// 	// 	num++;

// 	/////////////////////////////////////////////////////////////////////////////////////////////
// 	//если помещается в одну строку с учетом пробелов(кол файлов)
// 	if(point < i) {
// 		while(array[num] != NULL) {
// 		mx_printstr(array[num]);
// 		mx_printstr(" ");
// 		num++;
// 	}
// 	mx_printstr("\n");
// 	num = 0;
// 	}


// 	int del = 0;


// 	if (point >= i) {
// ///////////////////////////////////////////////////////
// while(point % i !=0)
// 	point++;

// del = point/i;

// int rev = coount_file;

// while((rev % del) != 0)
// 	rev++;

// if(((rev /del) * z) > i)
// 	del++;

// ///////////////////////////////////////////////////////		
// 		//while((point % del != 0) && (del <= coount_file))
// 			//del++;  //количество строк которое нужно будет вывести
// 		//printf("kol strok %d\n", del);
// 		int sgag = coount_file/del;  // =5
// 		int resurs = 0;
// 		int ss = 0;
// 		while(resurs < del) {
// 			num = resurs;
// 			while(num < coount_file) {
// 				mx_printstr(array[num]);
// 				//printf(" ");
// 				num = num + del;
// 				ss++;
// 			}
// 			mx_printstr("\n");
// 			resurs++;
// 			num = 0;
// 		}
// 	} 
// 	///////////////////////////////////////////////////////////////////////////////////////////
// 	//если куб - не работает
//}
