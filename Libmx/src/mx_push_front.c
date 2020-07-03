#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
	t_list *file;
	file = mx_create_node(data);
	file->next = *list;
	*list = file;
}
