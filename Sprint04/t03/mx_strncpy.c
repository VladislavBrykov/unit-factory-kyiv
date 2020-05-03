char *mx_strncpy(char *dst, const char *src, int len) {

    int c = 0;                  //obiavili peremennyu i zapustili cicl
    while(src[c] && c < len) {
        dst[c] = src[c];
        c++;
    }
    while(c < len) {
        dst[c] = '\0';
        c++;
    }
    return dst;
}
