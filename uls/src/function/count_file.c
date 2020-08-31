#include "uls.h"

//Можно вынести в отдельную функцию 
//количество тектовых файлов среди указанных argv
//для выделения памяти под массив строк

int count_file(char **name, int argc) {   
	void *dir = NULL; 							
	char *file = NULL;
	int j = 1;
	int count_file = 0;	
	
	while(name[j]) {
		dir = opendir(name[j]);
			if(dir == NULL) {
				file = mx_file_to_str(name[j]);

			if (file != NULL) 
				count_file++;
		}
		j++;
	}	
	//printf("%d\n", count_file); 
	return count_file;
}
