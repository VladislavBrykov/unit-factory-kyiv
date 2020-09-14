#include "uls.h"

static void reverse_str_arr(char **arr, int amount) {
    char *tmp_ch;
    int i = 0;
    int j = amount - 1;

    while (i < j) {
        tmp_ch = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp_ch;
        j--;
        i++;
    }
}

static void reverse_data_1(data_t ***data, int amount) {
    data_t **tmp_data;
    int i = 0;
    int j = amount - 1;

    while (i < j) {
        tmp_data = data[i];
        data[i] = data[j];
        data[j] = tmp_data;
        j--;
        i++;
    }
}

static void reverse_data_2(data_t **data) {
    int i = 0;
    int j = 0;
    data_t *tmp_data;

    for ( ; data[j] != NULL; j++);
    for (j--; i < j; i++, j--) {
        tmp_data = data[i];
        data[i] = data[j];
        data[j] = tmp_data;
    }
}


void reverse_sorting(data_t ****data, start_t *start_data) {
    char *tmp_ch;
    data_t **tmp_data1;
    data_t *tmp_data2;

    if (start_data->files_num > 1) {
        reverse_str_arr(start_data->files, start_data->files_num);
        reverse_data_1(data[0], start_data->files_num);
    }
    if (start_data->dirs_num > 0) {
        reverse_str_arr(start_data->dirs, start_data->dirs_num);
        reverse_data_1(data[2], start_data->dirs_num);
        reverse_data_1(data[1], start_data->dirs_num);
        for (int i = 0; i < start_data->dirs_num; i++)
            reverse_data_2(data[1][i]);
    }
}
