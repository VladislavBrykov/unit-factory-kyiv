#include "libmx.h"

int mx_list_size(t_list *list) {
    t_list *temp = NULL;
    int count = 0;

    if (list) {
        temp = list;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
    }
    return count;
}
