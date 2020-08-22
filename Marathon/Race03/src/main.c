#include "header.h"

int main(int argc, char const *argv[]) {
	int *c = 0;
	char *b = NULL;
	if (argc != 6) {
		mx_printerr("usage: ./race03 [card1] [card2] [card3] [card4] [card5]\n");
		return 0;
	}
	if (!mx_is_valid(argv))
		return 0;
	
	c = mx_to_int(argv);
	b = mx_to_char(argv);
	mx_sort(c, b);
	if (mx_is_duplicate(argv))
		return 0;
	mx_printstr(mx_result(c, b));
	return 0;
}
