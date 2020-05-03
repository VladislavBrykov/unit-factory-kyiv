#include "list.h"

void mx_pop_back(t_list **list) {
	if (*list != NULL || list != NULL) {
		if ((*list)->next == NULL) {
			(*list)->data = NULL;
			free(*list);
			*list = NULL;
		}
		else {
			t_list *back = *list;
			while (back->next->next)
				back = back->next;
			back->next->data = NULL;
			free(back->next); //osvobozdenie pamati
			back->next = NULL; //sbros
		}
	}
}

