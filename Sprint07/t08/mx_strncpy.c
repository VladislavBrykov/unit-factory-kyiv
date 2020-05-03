char *mx_strncpy(char *dst, const char *src, int len) {
    char *ret = dst;
    do {
        if (!len--)
            return ret;
    } while ((*dst++ = *src++));
    while (len--)
        *dst++ = 0;
    return ret;
}
