int mx_strlen(const char *s);
char *mx_strchr(const char *s, int c);
int mx_strncmp(const char *s1, const char *s2, int n);

char *mx_strstr(const char *s1, const char *s2) {
	char *s = (char *) s1;
	int file = mx_strlen(s2);
	while(*s) {
		if(!mx_strncmp(s, s2, file))
			return s;
		s++;
	}
	return 0;
}
