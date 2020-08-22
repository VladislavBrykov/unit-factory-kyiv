#include <stdlib.h>
//#include <stdio.h>

char *mx_strnew(const int size) {
    char *str = NULL;

    if (size < 0) 
        return NULL;
    str = (char*) malloc (sizeof(char) * (size +1));
    if (str == 0) 
        return NULL;
    for (int i = 0; i < size; i++) {
        str[i] = '\0';
    }
    str[size] = '\0';
    return str;
}

/*int main() {
    printf("%s", mx_strnew(10));
    return 0;
}*/
