#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    int i = 0;

    if (arr && delim) {
        while (arr[i]) {
            mx_printstr(arr[i++]);
            if (arr[i]) 
                mx_printstr(delim);
        }
        write(1, "\n", 1);
    }
}

// int main() {
//     const char *delim = "----";
//     char *arr[2] = {"Hello", "world!", "How are you?", NULL};
//     mx_print_strarr(arr, delim);
//     return 0;
// }
