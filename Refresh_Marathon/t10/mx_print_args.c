void mx_printchar(char c);
int mx_strlen(const char *s);
void mx_printstr(const char *s);

int main(int argc, char const *argv[]) {
	argc = 5;
	int i = 1;

	while (argv[i]) {
		mx_printstr(argv[i]);
		mx_printchar('\n');
		i++;
	}
	return 0;
}
