#include "uls.h"

static void starting_data(largest_t *largest) {
    largest->namelen = 0;
    largest->bloknumlen = 0;
    largest->linknumlen = 0;
    largest->groupidlen = 0;
    largest->useridlen = 0;
    largest->indnumlen = 0;
    largest->sizelen = 0;
    largest->tot_block = 0;
    largest->quantity = 0;
}

void largest_init(largest_t ***largest, start_t *start_data) {
    if (start_data->files_num < 1)
        largest[0] = NULL;
    else {
        largest[0] = malloc(sizeof(largest_t*));
        largest[0][0] = malloc(sizeof(largest_t));
        starting_data(largest[0][0]);
    }
    if (start_data->dirs_num < 1)
        largest[1] = NULL;
    else {
        largest[1] = malloc(sizeof(largest_t*) * start_data->dirs_num);
        for (int i = 0; i < start_data->dirs_num; i++) {
            largest[1][i] = malloc(sizeof(largest_t));
            starting_data(largest[1][i]);
        }
    }
}
