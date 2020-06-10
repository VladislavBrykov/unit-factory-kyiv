#include "list.h"

void mx_push_front(t_list **list, void *data) {
	t_list *file;
	file = mx_create_node(data);
	file->next = *list; //sohranenie pola dannyh dobavlaemogo yzla
	*list = file;
}

/*int main() {
	мейн не работает
	t_list *first = mx_create_node("Hello");
	mx_push_front(&first, "first");
	mx_push_front(&first, "second");
	mx_push_front(&first, "s");
	
	while(first) {
		printf("%s\n", first->second);
		first = first->next;
	}

	return 0;
}
*/