#include "uls.h"
static void swap_data(char **string, data_t ***data, int i, int j) {
    char *temp = NULL;
    data_t **tmp = NULL;

    temp = string[i];
    string[i] = string[j];
    string[j] = temp;
    tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

static void files_sorter(format_t *format, data_t ***data, char **files_names, int amount) {
    if (format->sorting.standart)
        for (int i = 0; i < amount - 1; i++)
            for (int j = i + 1; j < amount; j++)
                if (mx_strcmp(files_names[i], files_names[j]) > 0)
                    swap_data(files_names, data, i, j);
    if (format->sorting.size)
        for (int i = 0; i < amount - 1; i++)
            for (int j = i + 1; j < amount; j++)
                if (data[i][0]->size < data[j][0]->size)
                    swap_data(files_names, data, i, j);
    if (format->sorting.time)
        for (int i = 0; i < amount - 1; i++)
            for (int j = i + 1; j < amount; j++)
                if (data[i][0]->date_m < data[j][0]->date_m)
                    swap_data(files_names, data, i, j);
}

static void dirs_sorter(format_t *format, data_t ****data, char **dirs_names, int amount) {
    data_t **tmp;

    if (format->sorting.standart)
        for (int i = 0; i < amount - 1; i++)
            for (int j = i + 1; j < amount; j++)
                if (mx_strcmp(dirs_names[i], dirs_names[j]) > 0) {
                    swap_data(dirs_names, data[1], i, j);
                    tmp = data[2][i];
                    data[2][i] = data[2][j];
                    data[2][j] = tmp;
                }
    if (format->sorting.size)
        for (int i = 0; i < amount - 1; i++)
            for (int j = i + 1; j < amount; j++) {
                if (data[2][i][0]->size < data[2][j][0]->size) {
                    swap_data(dirs_names, data[1], i, j);
                    tmp = data[2][i];
                    data[2][i] = data[2][j];
                    data[2][j] = tmp;
                }
            }
    if (format->sorting.time)
        for (int i = 0; i < amount - 1; i++)
            for (int j = i + 1; j < amount; j++)
                if (data[2][i][0]->date_m < data[2][j][0]->date_m) {
                    swap_data(dirs_names, data[1], i, j);
                    tmp = data[2][i];
                    data[2][i] = data[2][j];
                    data[2][j] = tmp;
                }
}

static void dirs_content_sorter(format_t *format, data_t **data) {
    data_t *tmp = NULL;

    if (format->sorting.standart)
        for (int i = 0; data[i] != NULL; i++) {
            for (int j = i + 1; data[j] != NULL; j++) {
                if (mx_strcmp(data[i]->name, data[j]->name) > 0) {
                    tmp = data[i];
                    data[i] = data[j];
                    data[j] = tmp;
                }
            }
        }
    if (format->sorting.size)
        for (int i = 0; data[i] != NULL; i++)
            for (int j = i + 1; data[j] != NULL; j++)
                if (data[i]->size < data[j]->size) {
                    tmp = data[i];
                    data[i] = data[j];
                    data[j] = tmp;  
                }
    if (format->sorting.time)
        for (int i = 0; data[i] != NULL; i++)
            for (int j = i + 1; data[j] != NULL; j++)
                if (data[i]->date_m < data[j]->date_m) {
                    tmp = data[i];
                    data[i] = data[j];
                    data[j] = tmp;  
                }
}

static void no_fd_sorter(start_t *start_data) {
    char *temp;

    for (int i = 0; i < start_data->no_fd_num; i++)
        for (int j = i + 1; j < start_data->no_fd_num; j++)
            if (mx_strcmp(start_data->no_file_dir[i], start_data->no_file_dir[j]) > 0) {
                temp = start_data->no_file_dir[i];
                start_data->no_file_dir[i] = start_data->no_file_dir[j];
                start_data->no_file_dir[j] = temp;
            }
}

void data_sorter(format_t *format, flags_t *flag, data_t ****data, start_t *start_data) {
    if (start_data->no_fd_num > 1)
        no_fd_sorter(start_data);
    if (start_data->files_num > 1)
        files_sorter(format, data[0], start_data->files, start_data->files_num);
    if (start_data->dirs_num > 1)
        dirs_sorter(format, data, start_data->dirs, start_data->dirs_num);
    for (int i = 0; i < start_data->dirs_num; i++)
        dirs_content_sorter(format, data[1][i]);
    if (format->sorting.revesre)
        reverse_sorting(data, start_data);
}
