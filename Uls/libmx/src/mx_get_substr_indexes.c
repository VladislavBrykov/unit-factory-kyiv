int mx_get_substr_indexes(const char *str, const char *sub, int index) {
    for (int i = index, j = 0, flag = 1; str[i] != '\0'; i++, j = 0, flag = 1) {
        if (str[i] == sub[j]) {
            while (sub[++j]) {
                if (sub[j] != str[i + j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                return i;
        }
    }
    return -1;
}
