#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int first = 0; 
    int last = size - 1;
    int middle;

    if (!*arr) {
        return -1;
    }
    while (first <= last) {
        (*count)++;
	        middle = (first + last) / 2;
	        if (mx_strcmp(s, arr[middle]) > 0) {
	            first = middle + 1;
	        } 
	        else if ( mx_strcmp(s, arr[middle]) == 0) {
	            return middle;
	        } 
	        else {
	            last = middle - 1;
            }
    } 
    *count = 0;
    return -1;
}
