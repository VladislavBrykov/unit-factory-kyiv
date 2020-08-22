#include "header.h"

bool mx_is_flush (char *b) {
	int flesh = 0;

	for (int i = 0; i < 4; ++i) {
		if (b[i] == b[i + 1]) {
		++flesh;
		}
	}
	return flesh == 4;
}
