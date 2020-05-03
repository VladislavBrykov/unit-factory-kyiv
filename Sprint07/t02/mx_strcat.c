int mx_strlen(const char *s);

char *mx_strcat(char *s1, const char *s2) {
    int n1 = mx_strlen(s1);
    int n2 = mx_strlen(s2);
    int i = n1;
    for (int j = 0; i < n1 + n2; i++) {
        s1[i] = s2[j];
        j++;
    }
    s1[i] = '\0';
    return s1;
}
