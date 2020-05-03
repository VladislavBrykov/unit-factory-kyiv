char *mx_strcpy(char *dst, const char *src) {
	int count = 0;			//novaia peremannaia
	while (src[count]) {		//cicl while "poka"
		dst[count] = src[count];
		count++; }
	dst[count] = '\0';
	return dst;
}
