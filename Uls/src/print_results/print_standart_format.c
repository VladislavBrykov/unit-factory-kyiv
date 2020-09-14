#include "uls.h"

static int size_consol(void) {
	struct winsize window;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);	
    return window.ws_col;
}

static void print_d_name(char *dir) {
    mx_printstr(dir);
    mx_printstr(":\n");
}

static void print_tot_blocks(int tot_bl) {
    mx_printstr("total ");
    mx_printint(tot_bl);
    mx_printchar('\n');
}

static int find_col_width(flags_t *flag, largest_t *largest) {
    int max_width = largest->namelen;

    if (flag->i)
        max_width += largest->indnumlen + 1;
    if (flag->s)
        max_width += largest->bloknumlen + 1;
    if (flag->F)
        max_width++;
    while ((++max_width % 8) != 0) {}
    return max_width;
}

void print_standart_format(data_t ****data, flags_t *flag, largest_t ***largest, start_t *start_data) {
    int consol_size = size_consol();
    int col_width = 0;
    bool print_dir_name = false;
    bool need_new_line = false;
    int signal = 0;

    if (start_data->no_fd_num > 0) {
        //print_dir_name = true;
        print_no_fd(start_data);
    }

    if (start_data->files_num > 0) {
        print_dir_name = true;
        col_width = find_col_width(flag, largest[0][0]);

                int l = 0;
                int p = 0;
                for(l = 0; data[0][l] != NULL; l++) { }
            print_standart_string_file(data[0], flag, largest[0][0], consol_size, col_width, l);
        signal++;
    }

    if (start_data->dirs_num > 0) {
        //if(signal > 0)
            //mx_printstr("\n");
        if (print_dir_name == true)
            need_new_line = true;
        for (int i = 0; i < start_data->dirs_num; i++) {
            col_width = find_col_width(flag, largest[1][i]);
            if (need_new_line == true)
                mx_printchar('\n');  
            if (print_dir_name == true || start_data->dirs_num > 1)
                print_d_name(start_data->dirs[i]);
            if (largest[1][i]->quantity > 0) {
                if (flag->s)
                print_tot_blocks(largest[1][i]->tot_block);
                print_standart_string(data[1][i], flag, largest[1][i], consol_size, col_width);
                mx_printchar('\n');
            }
            need_new_line = true;    
        }
    }
}
