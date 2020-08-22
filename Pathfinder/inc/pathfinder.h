#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

struct input_data {
    char *string;
    int file_len;
    int num_of_islands;
    int num_of_bridges;
    char *uniqe_islands;
    int **adj_matrix;
    int **path_matrix;
    int **visit_matrix;
    int *route_arr;
    int *dist_arr;
    int begin_index;
    int *cleaner_flag;
    int **route_list;
    int **dist_list;
}      in_data;

void error_handling(int argc, char *filename);
void invalid_argc(int argc);
void invalid__file_no_exists(char *filename);
void invalid_file_empty(char *filename);
void invalid_first_line(void);
int my_atoull(const char *str);
void invalid_format_line(void);
void inv_number_of_islands(void);
void inv_duplicate_bridges(void);
void invalid_sum_of_bridges(void);

void adjacency_matrix_init(void);
void path_matrix_init(void);
void dajkstra(void);
void create_visit_route_dist_matrixes(void);
void route_dist_creating(int start_island);
void matrix_cleaner(int num, int i, int temp, int ferst_isl);
void init_help_arr(int num);
void print_results(int one, int two);

void route_dist_holder_mem_free(void);
void route_dist_holder_arr_adder(void);
void route_dist_holder_malloc(void);
void sort_results(void);

#endif
