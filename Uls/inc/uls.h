#ifndef ULS_H
#define ULS_H

#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <pwd.h>
#include <errno.h>
#include <sys/ioctl.h>

typedef struct flags {
    char *all_flags;
    bool A;
    bool F;
    bool S;
    bool a;
    bool d;
    bool g;
    bool h;
    bool i;
    bool l;
    bool n;
    bool m;  //визуально не работает
    bool o;
    bool r;
    bool s;
    bool t;
    bool one;
}              flags_t;

typedef struct start_data_list {
    char **dirs;              /* NULL-terminated 2d arr with names of DIRECTORIES from output */
    int dirs_num;             /* number of dirs in dirs array */
    char **files;             /* NULL-terminated 2d arr with names of FILES from output */
    int files_num;            /* number of files in files array */ 
    char **no_file_dir;       /* NULL-terminated 2d arr with names of DIR/FILES that don't exist */
    int no_fd_num;            /* number of non files of dirs in no_file_dir array */ 
}              start_t;

typedef struct sorting_type {
    bool revesre;
    bool standart;
    bool time;
    bool size;
}              sorting_t;

typedef struct print_format {
    bool standart;              /* true - print output to terminal in lines when, no -l, -n, -o, -g, -1, or -m flags*/
    bool long_format;           /* true if -l, -n, -o, -g */
    bool one_per_line;          /* true if -1 */
    bool with_commas;           /* true if -m */
    bool print_in_terminal;     /* true - no "| cat" or other options while start */
    sorting_t sorting;
    bool human_readable;
}              format_t;

typedef struct data_storage {   /* structure that keeps all needed infomationt about every file or folder */
    char *name;
    long long blok;
    char *block_ch;
    unsigned long long ind_num;
    long long size;
    char *size_ch;
    long date_m;
    char *date;
    char type;
    char *rights;
    char plus_or_at;
    unsigned short link_num;
    char *link_num_ch;
    char *user_id;
    char *group_id;
    char *link;
    char *ind_num_ch;
}              data_t;

typedef struct largest_len {    /*  structure that keeps largest length of every needed  */
    short namelen;              /*  field for every folder, and all files from output    */
    long long tot_block;
    short bloknumlen;
    short indnumlen;
    short linknumlen;
    short sizelen;
    short useridlen;
    short groupidlen;
    short quantity;
}              largest_t;

void flags_init(flags_t *flag);
void format_init(format_t *format);
void input_parser(int argc, char **argv, flags_t *flag, format_t *format, start_t *start_data);
void flag_detector(int count_flags, int argc, char **argv, flags_t *flag);
void file_dir_detector(int count_flags, int argc, char **argv, format_t *format, start_t *start_data);
void largest_init(largest_t ***largest, start_t *start_data);
void format_detector(format_t *format, flags_t *flag, start_t *start_data);
void data_collector(format_t *format, flags_t *flag, start_t *start_data, data_t ****data);
void get_data(data_t *data, flags_t *flag, format_t *format, char *dir_name);
void data_sorter(format_t *format, flags_t *flag, data_t ****data, start_t *start_data);
void reverse_sorting(data_t ****data, start_t *start_data);
void data_get_maxlen(largest_t ***largest, data_t ****data, start_t *start_data, flags_t *flag);

void print_long_format(data_t ****data, flags_t *flag, largest_t ***largest, start_t *start_data);
void print_no_fd(start_t *start_data);
void print_long_string(data_t **data, flags_t *flag, largest_t *largest);
void print_with_commas_format(data_t ****data, flags_t *flag, largest_t ***largest, start_t *start_data);
void print_with_coma_string(data_t **data, flags_t *flag, largest_t *largest);
void print_one_per_line_format(data_t ****data, flags_t *flag, largest_t ***largest, start_t *start_data);
void print_one_per_line_string(data_t **data, flags_t *flag, largest_t *largest);
void print_standart_format(data_t ****data, flags_t *flag, largest_t ***largest, start_t *start_data);
void print_standart_string(data_t **data, flags_t *flag, largest_t *largest, int console_size, int col_width);

void print_standart_string_file(data_t ***data, flags_t *flag, largest_t *largest, int console_size, int col_width, int l); //моя

char *size_to_readable(long long size);
void err_ill_option(char c, flags_t *flag);

// void free_mem(data_t *data, start_t *start_data);

#endif
