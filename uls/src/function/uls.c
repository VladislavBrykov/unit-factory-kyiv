#include "uls.h"

void uls(int argc, int i, char **name) {
	DIR *d;
    struct dirent *directory;
    int j = 1;
    bool flag = false;

for ( ; j < argc; j++) {
    if (name[j][0] != '-') {
        flag = true;
        break;
    }
}

if (flag)
    d = opendir(name[j]);   
else 
    d = opendir("./");

while ((directory = readdir(d)) != NULL) {
            if (directory->d_name[0] != '.') {
                mx_printstr(directory->d_name);
                mx_printchar('\n');
            }
        }
        closedir(d);

}
