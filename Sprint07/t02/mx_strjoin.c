#include <stdio.h>

int mx_strlen(const char *s);		//bydem ispolzovat
char *mx_strnew(const int size);	//bydem ispolzovat
char *mx_strcpy(char *dst, const char *src); //bydem ispolzovat

char *mx_strjoin(char const *s1, char const *s2) {  //new function
    if (s1 == 0 || s2 == 0) {  //stavim uslovie
        return 0;		//esli vipolnaetsa
    }
    int pr1 = mx_strlen(s1); //obiavlaem peremennie pr1 i pr2
    int pr2 = mx_strlen(s2);
    char *result = mx_strnew(pr1 + pr2);
    if (result == 0) {
        return 0;
    }
    mx_strcpy(result, s1);
    mx_strcpy(result + pr1, s2);
    return result;
}

//int main() {
//       char arr1[] = "unit";
//        char arr2[] = "factory";
//        printf("%s",mx_strjoin(arr1, arr2));
//}

