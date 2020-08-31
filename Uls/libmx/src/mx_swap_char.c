void mx_swap_char(char *s1, char *s2) {
    char buff = 0;
    
    if (s1 && s2) {
        buff = *s1;
        *s1 = *s2;
        *s2 = buff;
    }
}

// int main() {
//     char str[] = "ONE";
//     mx_swap_char(&str[0], &str[1]);
//     printf("%s\n", str);
//     return 0;
// }
