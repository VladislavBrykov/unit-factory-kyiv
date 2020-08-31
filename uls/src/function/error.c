#include "uls.h"

char **sort_pack_error(start_t *start_data) {
	int i = 0;
	char **dir = malloc(sizeof(char*) * (start_data->no_fd_num+ 2));
	dir[0] = mx_strnew(1);
	for (int i = 1; i <= start_data->no_fd_num; ++i)	{
		dir[i] = mx_strnew(mx_strlen(start_data->dirs[i - 1]));
	}
	dir[0] = mx_strcpy(dir[0], " ");
	for (int i = 1; i <= start_data->no_fd_num; ++i)	{
		dir[i] = mx_strcpy(dir[i], start_data->no_file_dir[i - 1]);
	}
	dir[start_data->dirs_num + 1] = NULL;
	// while(dir[i] != NULL) {
	// 	mx_printstr(dir[i]);
	// 	mx_printstr("\n");
	// 	i++;
	// }
return dir;
}


// void error(char **name) {
// 	char **dir = erro(start_t *start_data); 
// 	char **file = NULL;
// 	int i = 1;

// 	while(dir[i]) != NULL 
// 		i++;

// printf("%d\n", i);
// 	file = my_bubble_sort_file(dir, i); 

// 	while (name[i] != NULL) {
// 		mx_printerr("uls: ");
// 		mx_printerr(name[i]);
// 		mx_printerr(": No such file or directory\n");
// 	}
// }
			
