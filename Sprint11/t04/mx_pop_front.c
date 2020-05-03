#include "list.h"

void mx_pop_front(t_list **list) {
	if (*list == NULL || list == NULL)
		return;
	t_list *file = (*list)->next;
	free(*list); //ochistka pamato
	*list = file; //sbros na NULL
}

