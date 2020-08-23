#include "uls.h"

void no_such_directory(char *name) {
	void *dir = NULL; 
	char *file = NULL;
	dir = opendir(name);    //как закрыть файл

	if(dir == NULL){
		file = mx_file_to_str(name);

		if(file == NULL) {
			mx_printerr("uls: ");
			mx_printerr(name);
			mx_printerr(": No such file or directory\n");
			exit(1);
		}

		if (file != NULL)
			mx_printerr(name);	
			mx_printerr("\n");
			exit(0);
	}
}
