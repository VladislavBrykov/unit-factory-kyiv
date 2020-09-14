#include "uls.h"

void get_data(data_t *data, flags_t *flag, format_t *format, char *dir_name) {
    struct stat sb;
    char *temp = NULL;
    temp = mx_strjoin(dir_name, "/");
    char *string = mx_strjoin(temp, data->name);
    free(temp);
    temp = NULL;
    lstat(string, &sb);
    data->ind_num = sb.st_ino;
    data->ind_num_ch = mx_itoa(data->ind_num);
    data->size = sb.st_size;
    data->blok = sb.st_blocks;
    data->block_ch = mx_itoa(data->blok);
    // if (format->long_format) { 
        switch (sb.st_mode & S_IFMT) {
            case S_IFBLK:  data->type = 'b'; format->human_readable = false; break;
            case S_IFCHR:  data->type = 'c'; format->human_readable = false; break;
            case S_IFDIR:  data->type = 'd'; break;
            case S_IFIFO:  data->type = 'p'; format->human_readable = false; break;
            case S_IFLNK:  data->type = 'l'; break;
            case S_IFREG:  data->type = '-'; break;
            case S_IFSOCK: data->type = 's'; format->human_readable = false; break;
            default:       data->type = '?'; break;
        }

        data->link_num = sb.st_nlink;
        data->link_num_ch = mx_itoa(data->link_num);

        data->rights = mx_strnew(9);
        data->rights = mx_strcpy(data->rights, "---------");
        unsigned short mode = sb.st_mode;
        if ((mode & 0000400) == 0000400)
            data->rights[0] = 'r';
        if ((mode & 0000200) == 0000200)
            data->rights[1] = 'w';
        if ((mode & 0000100) == 0000100)
            data->rights[2] = 'x';
        if ((mode & 0000040) == 0000040)
            data->rights[3] = 'r';
        if ((mode & 0000020) == 0000020)
            data->rights[4] = 'w';
        if ((mode & 0000010) == 0000010)
            data->rights[5] = 'x';
        if ((mode & 0000004) == 0000004)
            data->rights[6] = 'r';
        if ((mode & 0000002) == 0000002)
            data->rights[7] = 'w';
        if ((mode & 0000001) == 0000001)
            data->rights[8] = 'x';
        if ((mode & 0004000) == 0004000)
            data->rights[2] = 's';
        if ((mode & 0002000) == 0002000)
            data->rights[5] = 's';
        if ((mode & 0001000) == 0001000)
            data->rights[6] = 't';

        acl_t acl = NULL;
        ssize_t xattr = 0;
        acl = acl_get_file(string, ACL_TYPE_EXTENDED);
        xattr = listxattr(string, NULL, 0, XATTR_NOFOLLOW);
            if (xattr < 0)
                xattr = 0;
            if (xattr > 0)
                data->plus_or_at = '@';
            else if (acl != NULL)
                data->plus_or_at = '+';
                else
                    data->plus_or_at = ' ';
        acl_free(acl);

        struct passwd *pwd;
        pwd = getpwuid(sb.st_uid);
        if (pwd != NULL && !flag->n) {
            data->user_id = mx_strnew(mx_strlen(pwd->pw_name));
            data->user_id = mx_strcpy(data->user_id, pwd->pw_name);
        }
        else {
            data->user_id = mx_strnew(12);
            data->user_id = mx_strcpy(data->user_id, mx_itoa((int)sb.st_uid));
        }
        struct group *gid;
        gid = getgrgid(sb.st_gid);
        if (gid != NULL && !flag->n) {
            data->group_id = mx_strnew(mx_strlen(gid->gr_name));
            data->group_id = mx_strcpy(data->group_id, gid->gr_name);
        }
        else {
            data->group_id = mx_strnew(12);
            char *temp = mx_itoa((int)sb.st_gid);
            data->group_id = mx_strcpy(data->group_id, temp);
            free(temp);
            temp = NULL;
        }
    
        data->size = sb.st_size;
        if (format->human_readable) 
            data->size_ch = size_to_readable(data->size);
        else 
            data->size_ch = mx_itoa(data->size);

        data->date_m = sb.st_mtime;
        char *time = ctime(&sb.st_mtime);
        data->date = mx_strnew(12);
        int i = 4;
        int j = 0;
        for ( ; j < 7; )
            data->date[j++] = time[i++];
        if (time[22] == '2')
            for ( ; j < 12; )
                data->date[j++] = time[i++];
        else 
            for (i = 19 ; j < 12; )
                data->date[j++] = time[i++];

        data->link = NULL;
        if (data->type == 'l') {
            char *temp = mx_strnew(1024);
            readlink(string, temp, 1023);
            data->link = mx_strnew(mx_strlen(temp));
            data->link = mx_strcpy(data->link, temp);
            free (temp);
        // }
    }
    free(string);
}
