#include "pathfinder.h"

static int smallest_find_unvisited(int i) {
    int index = 0;
    int minimal = INT_MAX;

    for (int ii = 0; ii < in_data.num_of_islands; ii++)
        if (in_data.path_matrix[ii][i] < minimal)
            if (in_data.visit_matrix[ii][i] != 1) {
                minimal = in_data.path_matrix[ii][i];
                index = ii;
            }
    return index;
}

static bool fill_route_dist_arr(int start_island, int finish_island) {
    int j = 0;
    int temp_i = 0;

    for (int i = 0; i < in_data.num_of_islands; i++) {
        if (in_data.path_matrix[i][finish_island] == in_data.adj_matrix[in_data.num_of_islands][finish_island] 
            && in_data.visit_matrix[i][finish_island] == 0) {
            in_data.visit_matrix[i][finish_island] = 1;
            in_data.route_arr[0] = finish_island;
            in_data.route_arr[1] = i;
            in_data.dist_arr[0] = in_data.adj_matrix[i][finish_island];
            if (in_data.begin_index != i && i != 0) {
                matrix_cleaner(1 , i, temp_i, finish_island); 
                in_data.begin_index = i;
            }
            while (i != start_island) {
                temp_i = i;
                i = smallest_find_unvisited(i);
                in_data.visit_matrix[i][temp_i] = 1;
                matrix_cleaner(2 , i, temp_i, finish_island); 
                in_data.dist_arr[++j] = in_data.adj_matrix[temp_i][i];
                in_data.route_arr[j + 1] = i;
            }
            return true;
        }
    }
    return false; 
}

void route_dist_creating(int start_island) {
    int finish_island = start_island + 1;
    int temp_i = 0;
    in_data.cleaner_flag[0] = 0;

    for (int i = start_island + 1; i < in_data.num_of_islands; i++) {
        route_dist_holder_malloc();
        in_data.begin_index = 0;
        init_help_arr(1);
        while(1) {
            init_help_arr(2);
            if (fill_route_dist_arr(start_island, finish_island)) {
                route_dist_holder_arr_adder();
                if (in_data.cleaner_flag[0] == 1) {
                    in_data.cleaner_flag[0] = 0;
                    matrix_cleaner(3 , i, temp_i, finish_island); 
                }
            }
            else
                break;
        }
        sort_results();
        print_results(start_island, finish_island);
        route_dist_holder_mem_free();
        finish_island++;
    }
}
