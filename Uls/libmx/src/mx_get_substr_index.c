int mx_get_substr_index(const char *str, const char *sub) {
    if (!sub || !str)
        return -2;
    for (int i = 0, j = 0, flag = 1; str[i] != '\0'; i++, j = 0, flag = 1) {
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

// int main() {
//     printf("%d\n", mx_get_substr_index("McDonalds Donuts", "on"));
//     return 0;
// }
