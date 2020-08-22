int mx_get_char_index(const char *str, char c) {
    int i = 0;
    
    if (!str) 
        return -2;
    while (str[i] != '\0') {
        if (str[i] == c)
            return i;
        i++;
    }
    return -1;
}

// int main() {
//     char string[] = {"hello world"};
//     char c = 'z';
//     printf("%d", mx_get_char_index(string, c));
//     return 0;
// }
