#include "uls.h"

void uls_a(char *name) {
	DIR *d;
    struct dirent *directory;
    name = "./";
    d = opendir(name);

directory = readdir(d); 
mx_printstr(directory->d_name);
              mx_printchar('\n');

        
        closedir(d);
}
