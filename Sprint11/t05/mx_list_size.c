#include "list.h"

int mx_list_size(t_list *list);
{
	int p;
	t_list *file;

	p = 0;
	file = list;
	if (file)
	{
		p = 1;
		while (file->next)
		{
			file = file->next;
			p += 1;
		}
	}
	return (p);
}
		
