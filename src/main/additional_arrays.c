#include "pathfinder.h"

void create_visit_route_dist_matrixes(void) {
    int a = in_data.num_of_islands;

    in_data.visit_matrix  = (int**)malloc(a * sizeof(int*) + a * a * sizeof(int));
	int *start = (int*)((char*)in_data.visit_matrix + a * sizeof(int*));
	for (int i = 0; i < a; i++) {
		in_data.visit_matrix[i] = start + i * a;
	}
    in_data.dist_arr = malloc((a + 1) * sizeof(int));
    in_data.route_arr = malloc((a + 1) * sizeof(int));
}
