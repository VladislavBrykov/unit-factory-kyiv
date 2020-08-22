char *mx_strcpy(char *dst, const char *src) {
	int count = 0;

	while (src[count]) {
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return dst;
}
