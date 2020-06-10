#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list   //sozdanie nowogo tipa
{
	void *data;    //hranimoe znachenie
	struct s_list *next;  //ykazatel na sledusiy yzel
}		t_list;   //nazvanie stryktyru

t_list *mx_create_node(void *data);

#endif

/*
struct s_list создаем новое имя типа s_list
будем пользоваться новым типом под именем t_list
понимаем что под этим именем будет храниться инфформация о 
*data и указатель на следующий елемент
*/

