#include "pathfinder.h"

void invalid_file_empty(char *filename) {
    int file_len = 0;

    if ((file_len = mx_file_len(filename)) < 1) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        exit(1);
    }
    in_data.file_len = file_len;
}
