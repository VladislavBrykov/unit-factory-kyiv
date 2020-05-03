#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct s_list   //sozdanie nowogo tipa
{
	void *data;    //hranimoe znachenie
	struct s_list *next;  //ykazatel na sledusiy yzel
}		t_list;   //nazvanie stryktyru

void mx_pop_front(t_list **list);

#endif

