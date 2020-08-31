#include "libmx.h"

char *mx_file_to_str(const char *file) {
    int fl = 0;
    int len = 0;
    int j = 0;
    char *string = NULL;
    char buff;

    if (!file)
        return NULL;
    if ((len = mx_file_len(file)) < 0)
        return NULL;
    if (!(string = mx_strnew(len)))
        return NULL;
    if (!(fl = open(file, O_RDONLY)))
        return NULL;
    while (read(fl, &buff, 1)) 
        string[j++] = buff;
    close(fl);
    return string;
}

// int main(int argc, char **argv) {
//     if(argc) 
//     printf("%s", mx_file_to_str(argv[1]));
//     return 0;
// }
