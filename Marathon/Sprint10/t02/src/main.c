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


/*
DESCRIPTION
Create a program that:
• has the same behaviour as the system utility cat
• prints the respective message to the stderr followed by a newline 
if a source file does not exist
Tips for this task
1. You do not need to process cat options.
2. Use the standard error for printing some errors.
3. You can use errno if you know how.

CONSOLE OUTPUT
>./mx_cat | cat -e
hello
hello$
>./mx_cat asdfg | cat -e
mx_cat: asdfg: No such file or directory
>./mx_cat Makefile
#contents of the file
>
*/

