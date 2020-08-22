int mx_count_words(const char *str, char delimiter) {
    int file = 0;
    while(*str) {
        if (*str != delimiter) {
            str++;
        }
        else {
            file++;
            while ( *str == delimiter) {
                    str++;
            }
        }
    }
    if(*(str-1) == delimiter) file--;
    else file++;
    return file;
}
