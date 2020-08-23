#include "uls.h"

void uls_a(int argc, int i, char **name) {
	DIR *d;
    struct dirent *directory;
    int search_flag = 1;
    int search_dir = 1;
    bool flag = false;
    bool dir = false;

for ( ; search_flag < argc; search_flag++) {
	if ((name[search_flag][0] == '-') && (name[search_flag][1])) {
        flag = true;
        break;
    }
}

for ( ; search_dir < argc; search_dir++) {
	if (name[search_dir][0] != '-') {
        dir = true;
        break;
    }
}

if(flag) {
	if (dir)
		d = opendir(name[search_dir]);

else
	d = opendir("./");


while ((directory = readdir(d)) != NULL) {
            if (directory->d_name[0]) {
                mx_printstr(directory->d_name);
                mx_printchar('\n');
            }
        }
        closedir(d);
    }

}
