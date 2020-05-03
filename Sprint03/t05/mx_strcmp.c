int mx_strcmp(const char *s1, const char *s2) {
	while (*s1 && *s1 == *s2) {		//zapuskaem cicl while
		s1++;						//yvelichivaem s1 i s2
		s2++;
	}
	return *(const unsigned char *)s1 - *(const unsigned char *)s2; //otnimaem
}
