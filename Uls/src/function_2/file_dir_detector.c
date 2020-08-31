#include "uls.h"

static int type_detector(char *argument) {
    struct stat sb;

    if (stat(argument, &sb) == -1)
        return 0;
    if ((sb.st_mode & S_IFMT) == S_IFDIR)
        return 1;
    return 2;
}

static char **arr_resize_fill(char* argument, char **arr) {
    char **temp = NULL;
    int i = 0;

    if (arr == NULL) {
        arr = malloc(sizeof(char *) * 2);
        arr[0] = mx_strnew(mx_strlen(argument));
        arr[0] = mx_strcpy(arr[0], argument);
        arr[1] = NULL;
    } 
    else {
        for ( ; arr[i] != NULL; i++) {}
        temp = malloc(sizeof(char *) * (i + 2));
        temp[i] = mx_strnew(mx_strlen(argument));
        temp[i] = mx_strcpy(temp[i], argument);
        temp[i + 1] = NULL;
        for (int j = 0; j < i; j++)
            temp[j] = arr[j];
        free(arr);
        arr = temp;
    }
    return arr;
}

void file_dir_detector(int count_flags, int argc, char **argv, format_t *format, start_t *start_data) {
    int i = count_flags;
    int j = 0;
    int dirs_num = 0;
    int files_num = 0;
    int no_fd_num = 0;

    start_data->dirs = NULL;
    start_data->files = NULL;
    start_data->no_file_dir = NULL;

    if (count_flags < argc - 1) {
        for (i++ ; i < argc; i++, j++) {
            switch (type_detector(argv[i])) {
                case 0: no_fd_num++; start_data->no_file_dir = arr_resize_fill(argv[i], start_data->no_file_dir); break;
                case 1: dirs_num++; start_data->dirs = arr_resize_fill(argv[i], start_data->dirs); break;
                case 2: files_num++; start_data->files = arr_resize_fill(argv[i], start_data->files); break;
            }
        }
    }
    else {
        start_data->dirs = malloc(sizeof(char*) * (2));
        start_data->dirs[0] = ".";
        start_data->dirs[1] = NULL;
        dirs_num = 1;
    }
    start_data->dirs_num = dirs_num;
    start_data->files_num = files_num;
    start_data->no_fd_num = no_fd_num;
    //распечатка входящих/файлов директорий
    // if (start_data->dirs != NULL) {
    //     mx_printstr("\n                     dirs:  ");
    //     for (int i = 0; start_data->dirs[i] != NULL; i++) {
    //        mx_printstr(start_data->dirs[i]);
    //         mx_printchar(' ');
    //     }
    //     mx_printchar('\n');
    // }
    // if (start_data->files != NULL) {
    //     mx_printstr("                    files:  ");
    //     for (int i = 0; start_data->files[i] != NULL; i++) {
    //         mx_printstr(start_data->files[i]);
    //         mx_printchar(' ');
    //     }
    //     mx_printchar('\n');
    // }
    // if (start_data->no_file_dir != NULL) {
    //     mx_printstr("No such file or directory:  ");
    //     for (int i = 0; start_data->no_file_dir[i] != NULL; i++) {
    //         mx_printstr(start_data->no_file_dir[i]);
    //         mx_printchar(' ');
    //     }
    //     mx_printchar('\n');
    //     mx_printchar('\n');
    // }
}
