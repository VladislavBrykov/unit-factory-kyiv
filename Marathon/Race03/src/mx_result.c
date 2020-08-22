#include "header.h"

char *mx_result(int *c, char *b) {
	char *res;

	if (mx_is_street(c) && mx_is_flush(b) && c[0] == 10)
		res = "Royal flush\n";
	else if (mx_is_street(c) && mx_is_flush(b) )
		res = "Straight flush\n";
	else if (mx_is_kare(c))
		res = "Four of a kind\n";
	else if (mx_pairs(c) == 3)
		res = "Full house\n";
	else if (mx_is_flush(b))
		res = "Flush\n";
	else if (mx_is_street(c))
		res = "Straight\n";
	else if (mx_is_set(c))
		res = "Three of a kind\n";
	else if (mx_pairs(c) == 2)
		res = "Two pair\n";
	else if (mx_pairs(c) == 1)
		res = "One pair\n";
	else
		res ="No pair\n";
	return res;
}
