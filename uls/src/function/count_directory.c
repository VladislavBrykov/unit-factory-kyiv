#include "uls.h"

//считает количество вложенных папок во всех аргументах

int count_directory(int argc, char **name) {
    DIR *dir;
    struct dirent *directory;                            
    int j = 1;
    int count_dir = 1; 
 
    while(name[j] != NULL) {
        dir = opendir(name[j]);
                  while ((directory = readdir(dir)) != NULL) {
                        count_dir++;
                    }
        j++;
    }   

    closedir(dir);
    return count_dir;
}
