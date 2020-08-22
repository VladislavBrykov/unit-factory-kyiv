#include "header.h"

bool mx_is_valid(const char *name[]) {
	char *tmp;

	for (int i = 1; i < 6; i++) {
		tmp = mx_strtrim(name[i]);
		if((mx_strlen(tmp) > 3 || mx_strlen(tmp) < 2) || (!mx_isdigit(tmp[0]) && !mx_is_rank(tmp[0]))) {
			mx_printerr("Invalid card: ");
			mx_printerr(name[i]);
			mx_printerr("\n");
			return false;
		}
		if (mx_strlen(tmp) == 3 && tmp[1] != '0' && tmp[0] != '1') {
			if (!mx_is_suit(tmp[2])) {
				mx_printerr("Invalid card: ");
				mx_printerr(name[i]);
				mx_printerr("\n");
				return false;
			}
			mx_printerr("Invalid card rank: ");
			tmp[2] = '\0';
			mx_printerr(tmp);
			mx_printerr("\n");
			return false;
		}
		if (!mx_is_suit(tmp[mx_strlen(tmp) - 1]) && tmp[0] == '0') {
			mx_printerr("Invalid card: ");
			mx_printerr(name[i]);
			mx_printerr("\n");
			return false;
		}
		if (!mx_is_suit(tmp[mx_strlen(tmp) - 1])) {
			mx_printerr("Invalid card suit: ");
			mx_printerr(&tmp[mx_strlen(tmp) - 1]);
			mx_printerr("\n");
			return false;
		}
		if ((!mx_isdigit(tmp[0]) && !mx_is_rank(tmp[0]) )|| tmp[0] == '0') {
			mx_printerr("Invalid card rank: ");
			tmp[1] = '\0';
			mx_printerr(tmp);
			mx_printerr("\n");
			return false;
		}
	}
	return true;
}
