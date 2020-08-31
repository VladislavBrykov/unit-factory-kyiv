#include "uls.h"

void get_data(data_t *data, flags_t *flag, format_t *format, char *dir_name) {
    struct stat sb;
    
    char *string = mx_strjoin(dir_name, "/");   //проследить за выделением памяти
    string = mx_strjoin(string, data->name);
    stat(string, &sb);
    if (flag->i)
        data->ind_num = sb.st_ino;
    if (flag->S)
        data->size = sb.st_size;
    if (flag->s)
        data->blok = sb.st_blocks;

    if (format->long_format) {      
        data->blok = sb.st_blocks;
        switch (sb.st_mode & S_IFMT) {
            case S_IFBLK:  data->type = 'b'; break;
            case S_IFCHR:  data->type = 'c'; break;
            case S_IFDIR:  data->type = 'd'; break;      // срабатывает когда файл, это ссылка  'l'
            case S_IFIFO:  data->type = 'p'; break;
            case S_IFLNK:  data->type = 'l'; break;      //не работает, проверить возможность применения на Mac OS
            case S_IFREG:  data->type = '-'; break;
            case S_IFSOCK: data->type = 's'; break;
            default:       data->type = '?'; break;
        }

        data->link_num = sb.st_nlink;

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
        if (pwd != NULL) {
            data->user_id = mx_strnew(mx_strlen(pwd->pw_name));
            data->user_id = mx_strcpy(data->user_id, pwd->pw_name);
        }
        else {
            data->user_id = mx_strnew(12);
            data->user_id = mx_strcpy(data->user_id, mx_itoa((int)sb.st_uid));
        }
        struct group *gid;
        gid = getgrgid(sb.st_gid);
        if (gid != NULL) {
            data->group_id = mx_strnew(mx_strlen(gid->gr_name));
            data->group_id = mx_strcpy(data->group_id, gid->gr_name);
        }
        else {
            data->group_id = mx_strnew(12);
            data->group_id = mx_strcpy(data->group_id, mx_itoa((int)sb.st_gid));
        }
    
        data->size = sb.st_size;

    }
    free(string);
}
