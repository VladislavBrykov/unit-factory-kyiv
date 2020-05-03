#include "list.h"

void
mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b)) {
    t_list *temp;
    t_list *next = NULL;

    if(*list && list) {
        temp = *list;
        while(list) {
            if(cmp((void *)*list, del_data) == true) {
                next = temp->next;
                free(temp);
                temp = next;
            }
            *list = NULL;
        }
    }
}
