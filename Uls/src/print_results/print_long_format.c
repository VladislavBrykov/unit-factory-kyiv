#include "uls.h"

static void print_d_name(char *dir) {
    mx_printstr(dir);
    mx_printstr(":\n");
}

static void print_tot_blocks(int tot_bl) {
    mx_printstr("total ");
    mx_printint(tot_bl);
    mx_printchar('\n');
}

void print_long_format(data_t ****data, flags_t *flag, largest_t ***largest, start_t *start_data) {
    bool print_dir_name = false;
    bool need_new_line = false;

    if (start_data->no_fd_num > 0) {
        print_dir_name = true;
        print_no_fd(start_data);
    }
    if (start_data->files_num > 0) {
        print_dir_name = true;
        for (int i = 0; i < start_data->files_num; i++)
            print_long_string(data[0][i], flag, largest[0][0]);
    }
    if (start_data->dirs_num > 0) {
        if (print_dir_name == true)
            need_new_line = true;
        for (int i = 0; i < start_data->dirs_num; i++) {
            if (need_new_line == true)
                 mx_printchar('\n');  
            if (print_dir_name == true || start_data->dirs_num > 1)
                print_d_name(start_data->dirs[i]);
            if (largest[1][i]->quantity > 0) {
                print_tot_blocks(largest[1][i]->tot_block);
                print_long_string(data[1][i], flag, largest[1][i]);
            }
            need_new_line = true;
        }
    }
}
