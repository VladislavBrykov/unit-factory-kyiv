#include "list.h"

t_list  *mx_create_node(void *data) {
    t_list *head_file = malloc(sizeof(t_list)); //videlenie pamaty pod koren spiska
    head_file->data = data;  //prisvaivanie znachenia uzlu
    head_file->next = NULL;  //prisvaivanie ykazatelu na sledusii element znachenia NULL
    return head_file;
}

int main() {
	t_list *head = mx_create_node("Hello");
	printf("%s\n", head->data);
	return 0;
}

/*head_file->data = data в элементе head_file 
в яейку data нужно положить значение =data
*/