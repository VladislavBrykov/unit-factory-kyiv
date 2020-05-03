char *mx_strcpy(char *dst, const char *src) {
    for (int i = 0; ; i++) {
        dst[i] = src[i];
        if (src[i] == '\0') {
            break;
        }
    }
    return dst;
}
