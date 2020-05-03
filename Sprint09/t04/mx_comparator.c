//#include <stdio.h>
//#include <unistd.h>
#include <stdbool.h>

int mx_comparator(const int *arr, int size, int x, bool(*compare)(int , int)) {
    for (int i = 0; i < size; i++) {
        if(compare(arr[i], x)) {
            return i;
        }
    }
    return -1;
}

//bool equal_nums(int a, int b) {
//    return a == b;
//}
//int main() {
//    int arr[] = {1, 4, 5, 6, 2};
//    printf("%d", mx_comparator(arr, 5, 2, equal_nums));
//    return 0;
//}
