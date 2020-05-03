int mx_strlen(const char *s);
void mx_swap_char(char *s1, char *s2);

void mx_str_reverse(char *s) {
	int dlina = mx_strlen(s) - 1;	//obiavlaem peremennyu dlina
	if (s)
	for (int i = 0; i <= dlina / 2; i++)	//xapuskaem cicl for
	mx_swap_char(&s[i], &s[dlina -i]);
}
