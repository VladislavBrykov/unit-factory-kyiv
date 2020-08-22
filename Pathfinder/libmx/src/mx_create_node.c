#include "libmx.h"

t_list  *mx_create_node(void *data) {
    t_list *head_file = malloc(sizeof(t_list));
    head_file->data = data;
    head_file->next = NULL;
    return head_file;
}

/*int main() {
	t_list* head = mx_create_node("Hello");
	printf("%s\n", head->data);
	return 0;
}*/
