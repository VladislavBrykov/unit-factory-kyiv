#include "pathfinder.h"

void path_matrix_init(void) {
    int a = in_data.num_of_islands;

    in_data.path_matrix  = (int**)malloc(a * sizeof(int*) + a * a * sizeof(int));
	int *start = (int*)((char*)in_data.path_matrix + a * sizeof(int*));
	for (int i = 0; i < a; i++) {
		in_data.path_matrix[i] = start + i * a;
	}
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            in_data.path_matrix[i][j] = INT_MAX;
}
