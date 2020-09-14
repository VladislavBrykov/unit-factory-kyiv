#include "uls.h"

static void biggest_finder(largest_t *largest, data_t *data) {
    largest->tot_block += data->blok;
    short namelen = mx_strlen(data->name);
    short groupidlen = mx_strlen(data->group_id);
    short useridlen = mx_strlen(data->user_id);
    short sizelen = mx_strlen(data->size_ch);
    short blocklen = mx_strlen(data->block_ch);
    short linklen = mx_strlen(data->link_num_ch);
    short indlen = mx_strlen(data->ind_num_ch);

    largest->quantity++;
    if (namelen > largest->namelen)
        largest->namelen = namelen;
    if (groupidlen > largest->groupidlen)
        largest->groupidlen = groupidlen;
    if (useridlen > largest->useridlen)
        largest->useridlen = useridlen;
    if (sizelen > largest->sizelen)
        largest->sizelen = sizelen;
    if (blocklen > largest->bloknumlen) 
        largest->bloknumlen = blocklen;
    if (linklen > largest->linknumlen)
        largest->linknumlen = linklen;
    if (indlen > largest->indnumlen)
        largest->indnumlen = indlen;
}

void data_get_maxlen(largest_t ***largest, data_t ****data, start_t *start_data, flags_t *flag) {
    if (start_data->files_num > 0)  {
        for (int i = 0; i < start_data->files_num; i++) {
            biggest_finder(largest[0][0], data[0][i][0]);
        }
    }
    if (start_data->dirs_num > 0)  {
        for (int i = 0; i < start_data->dirs_num; i++) {
            for (int j = 0; data[1][i][j] != NULL; j++) {
                biggest_finder(largest[1][i], data[1][i][j]);
            }
        }
    }
}
