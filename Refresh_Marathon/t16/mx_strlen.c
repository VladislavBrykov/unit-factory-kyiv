int mx_strlen(const char *s) {
    for (const char *i = s;; i++)
        if (!*i)
        return i-s;
}
