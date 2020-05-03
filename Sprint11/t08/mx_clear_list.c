#include "list.h"

void mx_clear_list(t_list **list) {
	t_list *new_yzel;
	t_list *yzel;
	
	yzel = *list;
	while (yzel) {
		new_yzel = yzel->next;
		free(yzel);              //ochistka pamati
		yzel = new_yzel; }
	*list = NULL;
}

