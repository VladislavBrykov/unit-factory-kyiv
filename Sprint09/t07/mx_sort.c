//#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

void mx_sort(int *arr, int size, bool (*f)(int, int)) {
    int buff;
    for(int j = 0; j < size-1; j++) {
        for(int i = 0; i < size-1-j; i++) {
            if(f(arr[i],arr[i+1])) {
                buff = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = buff;
            }
        }
    }
}

//bool compare(int a, int b) {
//    return a > b;
//}
//
//int main() {
//    int n = 5;
//    int arr[] = {4, -3, 2, 0, 1};
//    mx_sort(arr,n, compare);
//    for(int i = 0; i < n; i++){
//        printf("%d ", arr[i]);
//    }
//}
