#include "libmx.h"

static int my_swap(char** arr, int s1, int s2) {
    char *buff = 0;

    buff = arr[s1];
    arr[s1] = arr[s2];
    arr[s2] = buff;
    return 1;
}

static void pre_swap(char **arr, int l_temp, int r_temp, int middle, int *counter) {
    while (l_temp < r_temp) {
        while (mx_strlen(arr[l_temp]) < mx_strlen(arr[middle]))
            l_temp++;
        while (mx_strlen(arr[r_temp]) > mx_strlen(arr[middle]))
            r_temp--;
        if (mx_strlen(arr[l_temp]) > mx_strlen(arr[r_temp]))
            *counter += my_swap(arr, l_temp, r_temp);
        l_temp++;
        r_temp--;
    }
}

int mx_quicksort(char **arr, int left, int right) {
    int counter = 0;
    int l_temp = left;
    int r_temp = right;
    int middle = (left + right) / 2;
    
    if (!arr)
        return -1;   
    pre_swap(arr, l_temp, r_temp, middle, &counter);
    if ((middle - left) > 1)
        counter += mx_quicksort(arr, left, middle - 1);
    if ((right - middle) > 1)
        counter += mx_quicksort(arr, middle + 1, right);
    return counter;
}

// int main(void) {
//     //char *arr[4] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
//     //char *arr[6] = {"DMC", "Clint Eastwood", "Dr Brown", "Einstein", "Jessica", "Biff Tannen"};
//     //char **arr = NULL;
//     printf("%d\n", mx_quicksort(arr, 0, 5));
//     // for (int i = 0; i < 6; i++) 
//     //      printf("%s  ", arr[i]);
//     return 0;
// }
