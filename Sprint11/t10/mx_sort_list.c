#include "list.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    if (list == NULL || cmp == NULL)
        return NULL;

    for (t_list *x = list; x->next != NULL; x = x->next) {
            t_list *y = x;
    for (t_list *z = x->next; z != NULL; z = z->next) {

    if (cmp(y->data, z->data))
            y = z;
    void *temp = y->data;
        y->data = x->data;
        x->data = temp;
        }
    }
    return list;
}
