#include "uls.h"

static char *fill_string(char *string, int string_width, short field_len, char *data_field, bool right_side) {
    int i = string_width - 1;
    for ( ; string[i - 1] == ' ' && i > 0; i--) {}
    if (i != 0)
        i += 1;
    if (right_side)
        i = i + field_len - mx_strlen(data_field);
    for (int j = 0; data_field[j]; j++) {
        string[i++] = data_field[j];  
    }
    return string;
}

void print_standart_string_file(data_t ***data, flags_t *flag, largest_t *largest, int console_size, int col_width, int l) {
    char *string = mx_strnew(col_width);
    int j = 0;
    int kount_files = l;
    int signal = 0;
    int max_long = 0;
    //for (kount_files = 0; data[kount_files] != NULL; kount_files++) { }

    //printf("1234567890");

    //printf("%s\n", *data[0][0]);
   // mx_printstr(data[0][1]);

    for (int i = 0; data[i] != NULL; i++) {
        mx_memset(string, ' ', col_width);
        if (flag->i) {
            string = fill_string(string, col_width, largest->indnumlen, data[i][0]->ind_num_ch, true);
        }
        if (flag->s) {
            string = fill_string(string, col_width, largest->bloknumlen, data[i][0]->block_ch, true);
        }
        string = fill_string(string, col_width, largest->namelen, data[i][0]->name, false);
        if(signal == 0)
            max_long = mx_strlen(string);
        if(max_long < mx_strlen(string))
            max_long = mx_strlen(string);
        signal++;
    }

    while((max_long % 8) != 0)
        max_long++;

    int length_of_all_lines = 0;
    length_of_all_lines = ((max_long * kount_files)); //моя длина всех строк сумарно

// printf("kount_files   %d\n", kount_files);
//     printf("length_of_all_lines   %d\n", length_of_all_lines);
//     printf("console_size     %d\n", console_size);

    if (length_of_all_lines <= console_size) {
        for (int i = 0; data[i] != NULL; i++) {
            mx_memset(string, ' ', col_width);
        
            if (flag->i) {
                string = fill_string(string, col_width, largest->indnumlen, data[i][0]->ind_num_ch, true);
            }

            if (flag->s) {
                string = fill_string(string, col_width, largest->bloknumlen, data[i][0]->block_ch, true);
            }

            string = fill_string(string, col_width, largest->namelen, data[i][0]->name, false);
        
            if (flag->F) {
                for (j = col_width - 1; string[j - 1] == ' ' && i > 0; j--) {}
                switch (data[i][0]->type) {
                    case 'd': string[j] = '/'; break;
                    case 'l': string[j] = '@'; break;
                    case '-': if (data[i][0]->rights[2] == 'x') string[j] = '*'; break;
                }
            }
            mx_printstr(string);
                        //mx_printstr("\n12345678\n");
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (length_of_all_lines > console_size) {
        int max = console_size / max_long;
        int count_files = kount_files;

        while ((kount_files % max) != 0) {
            kount_files++;
        }

        int del = kount_files/max;
        int resurs = 1;
    

        while((kount_files % del) != 0)
            del++;  //количество столбцов и шаг

        int shag = del;
        int i = 0;
        int ii = 0;

        while(shag > 0) {
            i = ii;

        while ((i < count_files)) {
            mx_memset(string, ' ', col_width);
            
            if (flag->i) {
                string = fill_string(string, col_width, largest->indnumlen, data[i][0]->ind_num_ch, true);
            }

            if (flag->s) {
                string = fill_string(string, col_width, largest->bloknumlen, data[i][0]->block_ch, true);
            }

            string = fill_string(string, col_width, largest->namelen, data[i][0]->name, false);
            
            if (flag->F) {
                for (j = col_width - 1; string[j - 1] == ' ' && i > 0; j--) {}
                
                switch (data[i][0]->type) {
                case 'd': string[j] = '/'; break;
                case 'l': string[j] = '@'; break;
                case '-': if (data[i][0]->rights[2] == 'x') string[j] = '*'; break;
                }
            }
            mx_printstr(string);
            i += del;
        }
    shag--;
    ii++;
    
    if(shag >= 0)
        mx_printstr("\n");
   
        }
    }
    mx_printstr("\n");
    free(string);
}
