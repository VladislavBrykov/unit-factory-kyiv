#include "header.h"

void mx_strdel(char **as) {
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
