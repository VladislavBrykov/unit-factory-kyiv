#include <unistd.h>

void mx_printchar(char c);
char *mx_strchr(const char *s, int c);
void mx_printstr(const char *s);
int mx_strlen(const char *s);


int main (int argc, char *argv[]) {
	int i;
	i = 0;
	if (argc == 1)
	{
		while (argv[0][i])
			mx_printchar(argv[0][i++]);
		mx_printchar('\n');
	}
	return 0;
}
