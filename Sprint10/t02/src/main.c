#include "mx_cat.h"

int main(int argc, char *argv[]) {
        char buff;
        int f_read = 0;
        if (argc == 1) {
                while(read(0,&buff,1)){
                        write(1,&buff,1);
                }
        exit(0);
        }
        f_read = open(argv[1], O_RDONLY);
        if (f_read == -1) {
                mx_printerr("mx_cat: ");
                mx_printerr(argv[1]);
                mx_printerr(": No such file or directory\n");
                close(f_read);
                exit(1);
        }
        while(read(f_read, &buff, 1)) {
                write(1, &buff, 1);
        }
        close(f_read);
        exit(0);
}
