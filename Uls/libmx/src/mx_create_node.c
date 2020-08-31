#include "libmx.h"

t_list *mx_create_node(void *data) {
    t_list *head = malloc(sizeof(t_list));
    if (!head) 
        return NULL;
    head->data = data;
    head->next = NULL;
    return head;
}

// int main() {
//     char *a = "Hello world!";
//   t_list *list = mx_create_node(a);
//   printf("%s\n", list->data);
//   return 0;
// }
