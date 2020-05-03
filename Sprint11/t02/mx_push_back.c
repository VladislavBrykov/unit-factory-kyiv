#include "list.h"

void mx_push_back(t_list **list, void *data) {
	t_list *file;
	file = *list;
	if (file) {
		while (file->next)
			file = file->next;
		list->next = mx_create_node(data); }
	else
		*list = mx_create_node(data); 
}

