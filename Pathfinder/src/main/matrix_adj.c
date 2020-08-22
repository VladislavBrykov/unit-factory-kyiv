#include "pathfinder.h"

static void create_build_matrix(void) {
    int a = in_data.num_of_islands;

    in_data.adj_matrix  = (int**)malloc((a + 2) * sizeof(int*) + (a + 2) * a * sizeof(int));
	int *start = (int*)((char*)in_data.adj_matrix + (a + 2) * sizeof(int*));
	for(int i = 0; i < a + 2; i++) {
		in_data.adj_matrix[i] = start + i * a;
	}
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            in_data.adj_matrix[i][j] = INT_MAX;
}

static int get_isl_num(char *island) {
    int index = 0;
    int j = 0;
    int k = 0;

    char *islands = in_data.uniqe_islands;
    for (int i = 0; i < in_data.num_of_islands; i++) {
        if (island[j] == islands[k]) {
            for ( ; (island[j] != '-' || island[j] != ',') && (islands[k] != ' ' || islands[k] != '\0'); ) {
                if (island[j] == islands[k]) {
                    k++;
                    j++;
                }
                else 
                    break;
                if ((island[j] == '-' || island[j] == ',') && (islands[k] == ' ' || islands[k] == '\0'))
                    return i;
            }    
        }
        for ( ; islands[k] != ' '; k++) {};
        k++;
        j = 0;
    }
    return -1;
}

void adjacency_matrix_init(void) {
    int i = 0;
    int x = 0;
    int y = 0;

    create_build_matrix();
    for ( ; in_data.string[i] != '\n'; i++);
    for (int count = 0; count < in_data.num_of_bridges; count++) {
        x = get_isl_num(&in_data.string[++i]);
        for ( ; in_data.string[i] != '-'; i++) {};   
        y = get_isl_num(&in_data.string[++i]);
        for ( ; in_data.string[i] != ','; i++) {};
        int a = mx_atoi(&in_data.string[++i]);
        for ( ; in_data.string[i] != '\n'; i++) {};
        in_data.adj_matrix[x][y] = a;
        in_data.adj_matrix[y][x] = a;
    }
}
