#include "libmx.h"

int mx_file_len(const char *filename) {
    int file = 0;
    int i = 0;
    char buff;

    if ((file = open(filename, O_RDONLY)) == -1)
        return -1;
    while (read(file, &buff, 1))
		i++;
	close(file);
    return i;
}
