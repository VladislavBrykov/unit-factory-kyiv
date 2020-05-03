#include "list.h"

void mx_pop_index(t_list **list, int index) {
    t_list *p_node = *list;
    int p_index = 0;


    if (index < 1)
        mx_pop_front(&p_rnode);
    while (p_rnode) {
        if (p_index == index - 1) {
            free(p_node->next);
            p_node->next = p_node->next->next;
            p_index++;
        }
        else {
            p_node = p_node->next;
            p_index++;
        }
    }
    if (p_index < index)
        mx_pop_back(&p_node);
}
