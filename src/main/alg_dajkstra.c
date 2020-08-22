#include "pathfinder.h"

static void fill_start_values(int line) {

    for (int i = 0; i < in_data.num_of_islands; i++)
        in_data.adj_matrix[in_data.num_of_islands][i] = INT_MAX;
    in_data.adj_matrix[in_data.num_of_islands][line] = 0;
    for (int i = 0; i < in_data.num_of_islands; i++)
        if (in_data.adj_matrix[line][i] < INT_MAX) {
            in_data.adj_matrix[in_data.num_of_islands][i] = in_data.adj_matrix[line][i];
            in_data.path_matrix[line][i] = in_data.adj_matrix[line][i];
            in_data.path_matrix[i][line] = in_data.adj_matrix[line][i];
        }
    for (int i = 0; i < in_data.num_of_islands; i++)
        in_data.adj_matrix[in_data.num_of_islands + 1][i] = 0;
    in_data.adj_matrix[in_data.num_of_islands + 1][line] = 1;
}

static bool check_fo_dont_work(void) {
    int num = 0;

    for (int i = 0; i < in_data.num_of_islands; i++) {
        if (in_data.adj_matrix[in_data.num_of_islands + 1][i] == 0)
            num++;
        if (num > 0)
            return false;
    }
    return true;
}

static int find_smallest_unvisited(void) {
    int index = 0;
    int min = INT_MAX;

    for (int i = 0; i < in_data.num_of_islands; i++)
        if (in_data.adj_matrix[in_data.num_of_islands][i] < min)
            if (in_data.adj_matrix[in_data.num_of_islands + 1][i] != 1) {
                min = in_data.adj_matrix[in_data.num_of_islands][i];
                index = i;
            }
    return index;
}

void dajkstra(void) {
    int num = in_data.num_of_islands;
    int index;
    in_data.cleaner_flag = malloc(3 * sizeof(int));

    for (int line_number = 0; line_number < in_data.num_of_islands - 1; line_number++) { 
        fill_start_values(line_number);
        while (!check_fo_dont_work()) {
            index = find_smallest_unvisited();
            for (int i = 0; i < num; i++)
                if (in_data.adj_matrix[index][i] < INT_MAX && in_data.adj_matrix[num + 1][i] != 1) {
                    in_data.path_matrix[index][i] = in_data.adj_matrix[index][i] + in_data.adj_matrix[num][index];
                    in_data.path_matrix[i][index] = in_data.adj_matrix[index][i] + in_data.adj_matrix[num][index];
                    if (in_data.path_matrix[index][i] < in_data.adj_matrix[num][i])
                        in_data.adj_matrix[num][i] =  in_data.path_matrix[index][i];   
                }
            in_data.adj_matrix[num + 1][index] = 1;
        }
        route_dist_creating(line_number);
    }
}
