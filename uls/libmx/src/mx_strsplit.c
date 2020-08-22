#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s) 
        return NULL;
    int words = mx_count_words(s, c);
    char **arr = (char**)malloc((words + 1) * sizeof(char*));
    int j = 0;

    arr[words] = (char*)NULL;
    for (int i = 0, size = 0; i < words; i++, size = 0) {
        while (s[j])
            if (s[j] == c) {
                j++;
            } 
            else {
                while (s[j] != c) {
                    size++;
                    j++;
                }
                break;
            }  
        arr[i] = mx_strnew(size);
        for (int z = 0; z < size; z++)
            arr[i][z] = s[j - size + z];
    }
    return (char**)arr;
}

// int main() {
//     const char s[] = "**Good bye,**Mr.*Anderson.****";
//     char **arr = mx_strsplit(s, '*');
//     for (int i = 0; arr[i] != NULL; i++) {
//         for (int j = 0; arr[i][j] != (char)NULL; j++)
//             write(1, &arr[i][j], 1);
//         write(1, "\n", 1);
//     }
// }
