#include "header.h"

bool mx_is_suit(char c) {
	if ( c == 'H' || c == 'C' || c == 'S' || c == 'D') {
		return true;
	}
	return false;
}
