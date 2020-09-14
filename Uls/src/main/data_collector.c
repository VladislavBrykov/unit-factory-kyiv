#include "uls.h"

static void copy_dirs_to_files(start_t *start_data) {
    int i = 0;
    char **temp = malloc(sizeof(char*) * (start_data->dirs_num + start_data->files_num + 1));
    for ( ; i < start_data->files_num; i++)
        temp[i] = start_data->files[i];
    for (int j = 0; j < start_data->dirs_num; j++, i++)
        temp[i] = start_data->dirs[j];
    temp[++i] = NULL;
    free(start_data->files);
    free(start_data->dirs);
    start_data->dirs = NULL;
    start_data->files = temp;
    start_data->files_num += start_data->dirs_num;
    start_data->dirs_num = 0;
}

static data_t **if_A_flag(format_t *format, flags_t *flag, data_t **data, char *dir_name) {
    DIR *d = opendir(dir_name);
    struct dirent *directory;
    int counter = 1;
    int i = 0;
    
    while ((directory = readdir(d)) != NULL)
        counter++;
    closedir(d);
    d = opendir(dir_name);
    data = malloc(sizeof(data_t*) * (counter - 2));
    for ( ; i < 2; i++)
        readdir(d);  
    for (i = 0; (directory = readdir(d)) != NULL; i++) {
        data[i] = malloc(sizeof(data_t));
        data[i]->name = malloc(sizeof(char) * directory->d_namlen);
        data[i]->name = mx_strcpy(data[i]->name, directory->d_name);
        get_data(data[i], flag, format, dir_name);
    }
    closedir(d);
    data[i] = NULL;
    return data;
}

static data_t **if_a_flag(format_t *format, flags_t *flag, data_t **data, char *dir_name) {
    DIR *d = opendir(dir_name);
    struct dirent *directory;
    int counter = 1;
    int i = 0;

    while ((directory = readdir(d)) != NULL)
        counter++;
    closedir(d);
    d = opendir(dir_name);
    data = malloc(sizeof(data_t*) * counter);
    while ((directory = readdir(d)) != NULL) {
        data[i] = malloc(sizeof(data_t));
        data[i]->name = malloc(sizeof(char) * directory->d_namlen);
        data[i]->name = mx_strcpy(data[i]->name, directory->d_name);
        get_data(data[i], flag, format, dir_name);
        i++;
    }
    closedir(d);
    data[i] = NULL;
    return data;
}

static data_t **if_default(format_t *format, flags_t *flag, data_t **data, char *dir_name) {
    DIR *d = opendir(dir_name);
    struct dirent *directory;
    int counter = 1;
    int i = 0;
    
    while ((directory = readdir(d)) != NULL) {
        if (directory->d_name[0] != '.')
            counter++;
    }
    closedir(d);
    d = opendir(dir_name);
    data = malloc(sizeof(data_t*) * counter);
    while ((directory = readdir(d)) != NULL)
        if (directory->d_name[0] != '.') {
            data[i] = malloc(sizeof(data_t));
            data[i]->name = malloc(sizeof(char) * (directory->d_namlen + 1));
            data[i]->name = mx_strcpy(data[i]->name, directory->d_name);
            get_data(data[i], flag, format, dir_name);
            i++;
        }
    closedir(d);
    data[i] = NULL;
    return data;
}

static data_t **files_data_filer(format_t *format, flags_t *flag, data_t **data, char *file_name) {
    data = malloc(sizeof(data_t*) * 2);
    data[0] = malloc(sizeof(data_t));
    data[1] = NULL;
    data[0]->name = malloc(sizeof(char) * mx_strlen(file_name));
    data[0]->name = mx_strcpy(data[0]->name, file_name);
    if (file_name[0] == '/')
        get_data(data[0], flag, format, "");
    else
        get_data(data[0], flag, format, ".");
    return data;
}

static data_t **dirs_data_filler(data_t **data, char *dir_name) {
    struct stat sb;

    data = malloc(sizeof(data_t*));
    data[0] = malloc(sizeof(data_t));
    data[0]->name = malloc(sizeof(char) * mx_strlen(dir_name));
    data[0]->name = mx_strcpy(data[0]->name, dir_name);
    stat(dir_name, &sb);
    data[0]->size = sb.st_size;
    data[0]->date_m = sb.st_mtime;    
    return data;
} 

void data_collector(format_t *format, flags_t *flag, start_t *start_data, data_t ****data) {
    if (flag->d == true) 
        copy_dirs_to_files(start_data);
    if (start_data->files_num > 0) {
        data[0] = malloc(sizeof(data_t**) * (start_data->files_num + 1));
        data[0][start_data->files_num] = NULL;
        for (int i = 0; i < start_data->files_num; i++)
            data[0][i] = files_data_filer(format, flag, data[0][i], start_data->files[i]);
    }
    else 
        data[0] = NULL;
    if (start_data->dirs_num > 0) {
        data[1] = malloc(sizeof(data_t**) * (start_data->dirs_num));
        for (int i = 0; i < start_data->dirs_num; i++) {
            if (flag->h)
                format->human_readable = true;
            if (flag->A == true)
                data[1][i] = if_A_flag(format, flag, data[1][i], start_data->dirs[i]);
            else 
                if (flag->a == true)
                    data[1][i] = if_a_flag(format, flag, data[1][i], start_data->dirs[i]);
                else
                    data[1][i] = if_default(format, flag, data[1][i], start_data->dirs[i]);
        }
        data[2] = malloc(sizeof(data_t**) * (start_data->dirs_num));
        for (int i = 0; i < start_data->dirs_num; i++)
            data[2][i] = dirs_data_filler(data[2][i], start_data->dirs[i]);
    }
    else {
        data[1] = NULL;
        data[2] = NULL;
    }
}
