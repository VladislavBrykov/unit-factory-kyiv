#include "pathfinder.h"

int main(int argc, char *argv[]) {
    error_handling(argc, argv[1]);
    adjacency_matrix_init();
    path_matrix_init();
    create_visit_route_dist_matrixes();
    dajkstra();

    free(in_data.string);
    free(in_data.uniqe_islands);
    free(in_data.adj_matrix);
    free(in_data.path_matrix);
    free(in_data.visit_matrix);
    free(in_data.route_arr);
    free(in_data.dist_arr);
    free(in_data.cleaner_flag);
    // system("leaks pathfinder");
}
