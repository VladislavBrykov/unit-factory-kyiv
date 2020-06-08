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

/*while(read(file, &buff, 1))
 write(1, &buff, 1);
функция рид возвращает 1 в случае успешного считывания 1 байта, 
передает во врайт. 
Цикл повторяется автоматически, пока пока +1 байт будет 
считывать информацию с файла

DESCRIPTION
Create a program that prints:
• the contents of a file given as an argument to the standard output
• error to the stderr followed by a newline in case of any errors
• usage: ./read_file [file_path] to the stderr followed by a newline if no or too
many arguments have been given
CONSOLE OUTPUT
>./read_file | cat -e
usage: ./read_file [file_path]
>./read_file file.txt
#the contents of the file
>./read_file unknown_file | cat -e
error
>
FOLLOW THE WHITE RABBIT
man stderr
*/
