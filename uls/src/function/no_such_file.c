#include "uls.h"

char **no_such_directory(char **name, int argc) {
	void *dir = NULL; 
	char *file = NULL;
	int coount_file = count_file(name, argc); 
	char **str_result = arr_init(argc, coount_file); //пустой массив - веделение памяти
	char **new_arr = arr_init(argc, coount_file);
	char **new_arr_2 = arr_init(argc, coount_file);
	int i = 1;
	int j = 1;
	int count = 0;
	int num_world = 0;
	int z = 0;

	while (name[i]) {
		dir = opendir(name[i]);
			if (dir == NULL) {
				file = mx_file_to_str(name[i]);
					if(file == NULL) {
						mx_printerr("uls: ");
						mx_printerr(name[i]);
						mx_printerr(": No such file or directory\n");
					}
					else if (file != NULL) {
						while(name[i][z] != '\0') {
							str_result[num_world][z] = name[i][z];
							z++;
						}
						num_world++;
						z = 0;
					}
			}
		i++;
		}
		str_result[num_world] = NULL;

	//int ount = arr_tab(str_result);  //максимальная длина строки 
										//ретерню округленное значение с учетом таба кратное 8

	new_arr = arr_with_space(str_result);  //на выходе массив со строками одинаковой длины
	new_arr_2 = my_bubble_sort_file(new_arr, coount_file);  //на выходе отсортированный массив со строками одинаковой длины



	///////////////////////////////////////////////////////////
	// int v = 0;
	// while(new_arr_2[v] != NULL) {
	// 	printf("%d    %s\n", v, new_arr_2[v]);
	// 	v++;
	// }
	///////////////////////////////////////////////////////////
	//printf("long new_arr_2[0] %d\n", mx_strlen(new_arr_2[0]));
	//если закрываю дир - выбивает ошибку, а так все работает
	//closedir(dir);  //segmentation fault 
free(str_result);
return new_arr_2; //отсортированный двумерный масив строк с названиями ФАЙЛОВ уже с пробелами
}

