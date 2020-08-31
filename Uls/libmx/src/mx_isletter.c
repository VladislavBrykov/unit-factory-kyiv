#include "libmx.h"

bool mx_isletter(char c) {
	if((c > 64 && c < 91) || (c > 96 && c < 123)) {
		return true;
	} else {
		return false;
	}
}
