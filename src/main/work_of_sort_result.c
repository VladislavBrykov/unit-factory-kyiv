#include "pathfinder.h"

static int int_arr(int *a, int *b) {
    for (int i = 0; a[i] != -1; i++) {
        if (a[i] > b[i]) {
           return 1;
        }
        if (a[i] < b[i]) {
           return 0;
        }
    }
    return 0;
}

void sort_results(void) {
    int *route_temp = NULL;
    int *dist_temp = NULL;

    for (int i = 0; in_data.route_list[i] != NULL; i++) {
        for (int j = i + 1; in_data.route_list[j] != NULL; j++) {
            if (int_arr(in_data.route_list[i], in_data.route_list[j])) {
                route_temp = in_data.route_list[i];
                in_data.route_list[i] = in_data.route_list[j];
                in_data.route_list[j] = route_temp;
                dist_temp = in_data.dist_list[i];
                in_data.dist_list[i] = in_data.dist_list[j];
                in_data.dist_list[j] = dist_temp;
            }
        }
    }
}
