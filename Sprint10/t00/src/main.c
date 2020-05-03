#include "readfile.h"
#include <stdio.h>
int main(int argc, char *argv[]) {
        char buff;
        int file = 0;
        if (argc != 2) {
                mx_printerr("usage: ./read_file [file_path]\n");
                return 0;
        }
        else {
                file = open(argv[1], O_RDONLY);
                if (file == -1) {
                        mx_printerr("error\n");
                        return 0;
                }
                else {
                while(read(file, &buff, 1))
                        write(1, &buff, 1);
                }
                close(file);
        }
        return 0;
}

