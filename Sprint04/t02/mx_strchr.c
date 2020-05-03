char *mx_strchr(const char *s, int c) {

	char *str = (char *) s;
	while(*str){
		if(*str == (char) c)
			return str;
		str++;
	}
	if(c == '\0')
		return str;
	return 0;
}
