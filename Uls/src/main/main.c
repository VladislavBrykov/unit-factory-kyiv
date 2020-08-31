#include "uls.h"

int main(int argc, char *argv[]) {

flags_t *flag = malloc(sizeof(flags_t));
    format_t *format = malloc(sizeof(format_t));
    start_t *start_data = malloc(sizeof(start_t));
    data_t ****data = malloc(sizeof(data_t***) * 2);

    flags_init(flag);
    format_init(format);
    input_parser(argc, argv, flag, format, start_data);
    format_detector(format, flag, start_data);
    data_collector(format, flag, start_data, data);
    



///////////////////////////////////////////////////////////////////////////////////////
//    очень нужный кусок кода
//просто оставю его десь
//никуда не перемещаю- работает    
/*************************************************************************************************************/
    //ошибки
// char **sss = sort_pack_error(start_data);
// int ttt = 0;
// while(sss[ttt] != NULL) {
//   //mx_printstr(s[t]);
//   //mx_printstr("\n");
//   ttt++;     
//   //printf("%d\n", ttt);                  //количество папок
//   //char **ssss = my_bubble_sort(sss, ttt);
// }
// if(ttt > 1) {
// char **sese = my_bubble_sort_file(sss, ttt);
// // int o = 0;
// // while(sese[o] != NULL) {
// //   mx_printstr(sese[o]);
// //   mx_printstr("\n");
// //   o++;
// // }
// print_err(sese);
// }
/*************************************************************************************************************/





int signal = 0; //для печати директорий нужен ли дир: если вышечто-то есть

char **s = sort_pack_dir(start_data);

// printf("%s\n", s[1]);
// printf("%s\n", s[2]);
int t = 0;
while(s[t] != NULL) {
  //mx_printstr(s[t]);
  //mx_printstr("\n");
  t++;                      //количество папок
}



char **ss = sort_pack_file(start_data);
int tt = 0;
while(ss[tt] != NULL) {
  //mx_printstr(ss[tt]);
  //mx_printstr("\n");
  tt++;
  signal++;
}       
                   //количество файлов
//////////////////////////////////////////////////////////////////////////////////////
  if(tt > 1) {
 no_such_directory(ss, tt);  //файлы
 printf_file_directory(ss, tt); 
}
if(t > 1) {
  if(tt > 1)
    mx_printstr("\n");
 uls(t, s);   //директории
 printf_directory(t, signal);
}
  
 





     //printf("files - %d, dirs - %d, no_fd - %d\n", start_data->files_num, start_data->dirs_num, start_data->no_fd_num);
    if (format->long_format) {
        for (int i = 0; i < start_data->files_num; i++) {
            printf("%c", data[0][i][0]->type);
            printf("%s", data[0][i][0]->rights);
            printf("%c ", data[0][i][0]->plus_or_at);
            printf("%d ", data[0][i][0]->link_num);
            printf("%s ", data[0][i][0]->user_id);
            printf("%s ", data[0][i][0]->group_id);
            printf("%llu ", data[0][i][0]->size);
            printf("%s\n", data[0][i][0]->name);
            printf("\n");
        }
        for (int j = 0; j < start_data->dirs_num; j++) {
            for (int i = 0; data[1][j][i] != NULL; i++) {
                printf("%c", data[1][j][i]->type);
                printf("%s", data[1][j][i]->rights);
                printf("%c ", data[1][j][i]->plus_or_at);
                printf("%d ", data[1][j][i]->link_num);
                printf("%s ", data[1][j][i]->user_id);
                printf("%s ", data[1][j][i]->group_id);
                printf("%llu ", data[1][j][i]->size);
                printf("%s\n", data[1][j][i]->name);
            }
            printf("\n");
        }
    } 
  //s_arguments = saearch_arguments(argc, argv);
  
  //if (s_arguments == 3)
  //uls(argc, i, argv);
//   if (s_arguments == 1)
// uls_only(argc, i, argv);
  //if ((s_arguments == 2) || (s_arguments == 4))
  //uls_a(argc, i, argv);
  //number_town(argc, i, argv);
  //my_bubble_sort(argc);

   //if(argc == 1)
   //uls_a(argv[i]);
   return 0;
    // system("leaks pathfinder");
}
