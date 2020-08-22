#include <unistd.h>

void mx_printchar(char c);

void mx_only_printable(void) {
        int i=0;
        for (i=127; i>=32; i--) {
        	mx_printchar(i); }
	mx_printchar ('\n');
}

int main()
{
	mx_only_printable();
	return 0;
}
