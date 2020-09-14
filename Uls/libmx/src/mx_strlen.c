int mx_strlen(const char *s) {
    int i = 0;
    while (s[i] != '\0') 
        i++;
    return i;
}

// int main () {
//     char b = 'c';
//     char *b1 = &b;
//     printf("%p\n", (void*)b1);
// }
