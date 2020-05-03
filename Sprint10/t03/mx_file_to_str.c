#include "file_to_str.h"
//#include <stdio.h>

char *mx_file_to_str(const char *filename) {
        char *result=(char *)malloc(sizeof(char)*2);
        int file = open(filename, O_RDONLY);
        if(file < 0) {
                return NULL;
        }
        return result;
        close(file);
        free(result);
        *result = 0;
}

//int main() {
//        printf("%s\n", mx_file_to_str("ttt")); ttt - Ñ„Ðfile viz text, when ttttt - null  
//        return 0;
//}
