#include "pathfinder.h"

static void print_island_by_index(int index) {
    int i = 0;

    for (int j = 0 ; j < index; j++) {
        while (in_data.uniqe_islands[++i] != ' ');
        i++;
    }
    while (mx_isletter(in_data.uniqe_islands[i])) {
        mx_printchar(in_data.uniqe_islands[i]);
        i++;
    }
}

static void print_path(int one_island, int two_island) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    print_island_by_index(one_island);
    mx_printstr(" -> ");
    print_island_by_index(two_island);
    mx_printchar('\n');
}

static void print_of_route(int one_island, int two_island, int i) {
    int leng = 1;

    mx_printstr("Route: ");
    print_island_by_index(one_island);
    mx_printstr(" -> ");
    if (in_data.route_list[i][2] != -1) {
        for ( ; in_data.route_list[i][leng + 1] != -1; leng++) {  
                print_island_by_index(in_data.route_list[i][leng]);
                mx_printstr(" -> ");
        }
    }
    print_island_by_index(two_island);
    mx_printchar('\n');
}

static void print_distance(int one_island, int two_island, int i) {
    int leng = 0;

    mx_printstr("Distance: ");
    if (in_data.dist_list[i][1] != -1) {
        for ( ; in_data.dist_list[i][leng] != -1; leng++) {
            mx_printint(in_data.dist_list[i][leng]);
            if (in_data.dist_list[i][leng + 1] != -1) {     
                mx_printstr(" + ");
            }
            else
                mx_printstr(" = ");
        }
    }
    mx_printint(in_data.adj_matrix[in_data.num_of_islands][two_island]);
    mx_printstr("\n========================================\n");
}

void print_results(int one, int two) {
    for (int i = 0; in_data.route_list[i] != NULL; i++) {
        print_path(one, two);
        print_of_route(one, two, i);
        print_distance(one, two, i);
    }
}
