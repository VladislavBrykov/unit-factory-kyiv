#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct s_list   //sozdanie nowogo tipa
{
	void *data;    //hranimoe znachenie
	struct s_list *next;  //ykazatel na sledusiy yzel
}		t_list;   //nazvanie stryktyru

void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_push_index(t_list **list, void *data, int index);
t_list *mx_create_node(void *data);

#endif

