#include "pathfinder.h"

static void init_visit_arr(void) {
    for (int i = 0; i < in_data.num_of_islands; i++)
        for (int j = 0; j < in_data.num_of_islands; j++)
            in_data.visit_matrix[i][j] = 0;
}

static void init_route_dist_arr(void) {
    for (int i = 0; i <= in_data.num_of_islands; i++)
        in_data.dist_arr[i] = -1;
    for (int j = 0; j <= in_data.num_of_islands; j++)
        in_data.route_arr[j] = -1;
}

void init_help_arr(int flag) {
    switch (flag) {
        case (1): init_visit_arr(); break;
        case (2): init_route_dist_arr(); break;
    }
}
