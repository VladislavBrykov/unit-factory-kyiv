#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list * front_node;

    front_node = mx_create_node(data);
    front_node->next = *list;
    *list = front_node;    
}
