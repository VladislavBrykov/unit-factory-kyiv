char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int i1 = 0;
    int i2 = 0;

    while (s1[++i1]);
    while (s2[i2])
        s1[i1++] = s2[i2++];
    s1[i1 + 1] = '\0';
    return s1;
}

// int main() {
//     char src[100] = "Hello ";
//     char *dst = mx_strcat(src, "world!");
//     printf("%s\n", dst);
//     return 0;
// }
