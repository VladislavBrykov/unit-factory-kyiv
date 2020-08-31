#include "uls.h"

static int arr_tab(char **arr) {  
	int i = 1;
	int j = 0;
	j = mx_strlen(arr[0]);

	while (arr[i] != NULL) {
		if(mx_strlen(arr[i]) > j) {
			j = mx_strlen(arr[i]);
			arr[i][j] = '\t';
			j = mx_strlen(arr[i]);  //дописываю таб к самому длинному слову массива
		}
		i++;
	}

	while (j % 8 != 0)
		j++;    /////////////////////////ретерню округленное значение с учетом таба кратное 8
	
	return j;
}

//смотрим на длину максимально длинного слова
//дописываем пробелы чтоб все строки имели одинаковую длину

char **arr_with_space(char **arr) { //заполнение пробелами + табуляция
	int i = 0;
	int j = 0;
	int a = 0;
	int k = 0;
	int z = 0;
	int num_num = num_max_file(arr); //номер элемента с максимальной длиной, 
	int max_long = mx_strlen(arr[num_num]);  //максимальная длина без таба

	if((max_long % 8) == 0) { //если длина кратна 8 + 8 (1 tab)
		i = 8;
		max_long = max_long + 8;
	}

	else {
		while((max_long % 8) != 0) {
			max_long++; //на выходе имею длину кратную 8 к ней приводу все остальные элементы
			i++;  //на сколько увеличили
		}
	}

////////////////////////////////////////////////////////////////////////	
	//сохраняю в структуры максимальную длину с учетом табов
// struct dirent *directory;
// in_data.max_long = max_long;
////////////////////////////////////////////////////////////////////////

	while(arr[j] != NULL) {
		a = mx_strlen(arr[j]);
		//while ((max_long - a) != 0) {
			k = max_long - a;
			//if((k % 8) == 0)
			//	k+=8;

			while((k % 8) != 0)
				k++;

			if(k == 8) 
				z = 1;
			if(k > 8)
				z = k/8;
			while(z != 0) {
				arr[j][a] = '\t';
				a++;
				z--;;
			}
		j++;
		}

return arr;  //на выходе массив со строками одинаковой длины
}

