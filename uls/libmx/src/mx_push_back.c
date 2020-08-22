#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list * back_node;

    back_node = *list;
    if (!back_node) {
        *list = mx_create_node(data);
    } 
    else {
        while (back_node->next)
            back_node = back_node->next;
        back_node->next = mx_create_node(data);
    }
}
