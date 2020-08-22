int mx_isspace(unsigned char c) {
    if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
        return 1;
    return 0;
}
