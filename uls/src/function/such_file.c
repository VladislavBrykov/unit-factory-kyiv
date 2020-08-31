#include "uls.h"

char **sort_pack_file(start_t *start_data) {
	int i = 0;
	char **dir = malloc(sizeof(char*) * (start_data->files_num + 2));
	dir[0] = mx_strnew(1);
	for (int i = 1; i <= start_data->files_num; ++i)	{
		dir[i] = mx_strnew(mx_strlen(start_data->files[i - 1]));
	}
	dir[0] = mx_strcpy(dir[0], " ");
	for (int i = 1; i <= start_data->files_num; ++i)	{
		dir[i] = mx_strcpy(dir[i], start_data->files[i - 1]);
	}
	dir[start_data->files_num + 1] = NULL;
	// while(dir[i] != NULL) {
	// 	mx_printstr(dir[i]);
	// 	mx_printstr("\n");
	// 	i++;
	// }
return dir;
}
