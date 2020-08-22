#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    t_list *current = NULL;
    t_list *store = lst;
    t_list *first = lst;
    void *swap_buff;

    while (lst) {
        current = store;
        while (current) {
            if (current->next && cmp(current->data, current->next->data)) {
                swap_buff = current->data;
                current->data = current->next->data;
                current->next->data = swap_buff;
            }
            current = current->next;
        }
        lst = lst->next;
    }
    return first;
}
