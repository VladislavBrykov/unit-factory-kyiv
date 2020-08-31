#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    char *buff;
    int counter = 0;
    
    for (int i = size; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (mx_strcmp(&arr[j][0], &arr[j + 1][0]) > 0) {
                counter++;
                buff = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buff;
            }
        }
    }
    return counter;
}
