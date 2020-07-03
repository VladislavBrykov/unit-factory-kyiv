#include "libmx.h"

int mx_list_size(t_list *list) {
    int file = 0;
    t_list *temp = NULL;

    if (list) {
        temp = list;
        while (temp != NULL) {
            file++;
            temp = temp->next;
        }
    }
    return file;
}
