#include "readfile.h"

int main(int argc, char const *argv[]) {
    int src;
    int dst;
    char buffer;

    if(argc != 3) {
        mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
        return 0;
    }
    
    src = open(argv[1], O_RDONLY);

    if(src <= 0) {
        mx_printerr("mx_cp: ");
        mx_printerr(argv[1]);
        mx_printerr(": No such file or directory\n");
        return 0;
    }
    
    dst = open(argv[2], O_RDONLY);
    if(dst == -1)
        dst = open(argv[2], O_WRONLY | O_CREAT);
    

    while(read(src, &buffer, 1))
        write(dst, &buffer, 1);

    close(src);
    close(dst);

return 0;
}
