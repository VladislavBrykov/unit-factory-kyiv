#include "list.h"

void mx_push_index(t_list **list, void *data, int index) {
    int file = 0;

    t_list *res = mx_create_node(data);
    t_list *temp = *list;
    int point = 0;

    if (index <= 0)
        mx_push_front(list, data);
    while (temp != NULL) {
        if (file == index -1) {
            res->next = temp->next;
            temp->next = res;
            point = 1;
        }
        temp = temp->next;
        ++file;
    }
    if (point != 1)
        mx_push_back(list, data);
}
