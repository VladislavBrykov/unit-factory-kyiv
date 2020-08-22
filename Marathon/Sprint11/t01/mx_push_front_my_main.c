#include "list.h"

void mx_push_front(t_list **list, void *data) {
	t_list * newfirst_node = (t_list*) malloc(sizeof(t_list));
	newfirst_node->data = data;
	newfirst_node->next = (*list);
	(*list) = newfirst_node;
}

/*int main() {
	t_list *first = mx_create_node("hello");

	mx_push_front(&first, "first");
	mx_push_front(&first, "second");
	mx_push_front(&first, "s");

	while(first) {
		printf("%s\n", first->data);
		first = first->next;
	}
	return 0;
}

у нас есть первый элемент, задача добавить второй и 
сделать так чтобы он ссылался на первый*/
