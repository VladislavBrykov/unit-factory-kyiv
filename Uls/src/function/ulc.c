#include "uls.h"

/*################################################################*/
//создание трехмерного массива, заполнен символами конца строки
//возможно вынести в отдельную функцию
void arr_init_3p(int argc, int number) {
  in_data.str_directory = (char***)malloc(sizeof(char**) * (argc));
  for (int i = 0; i < argc; i++) {
    in_data.str_directory[i] = (char**)malloc(sizeof(char*) * (number + 2));
    for (int j = 0; j < number; j++) {
      in_data.str_directory[i][j] = mx_strnew(255);
    }
  }
}
/*################################################################*/

///////////////////////////////////////////////////////////////////////////
void uls(int argc, char **name) {
	DIR *d = NULL;
    struct dirent *directory;
     int z = 0;
     int num = 1;
     int num_dir = 0;
     int num_in_dir = 0;
    int number = count_directory(argc, name);
    arr_init_3p(argc, number);
    //char *zero_str = NULL;
  if (argc > 1) {
     while (num < argc) {
       d = opendir(name[num]);
         while((name[num][z] != '\0') && (name[num] != NULL)) {
           in_data.str_directory[num_dir][num_in_dir][z] = name[num][z];
           z++;
         }
         z=0;
         num_in_dir++;
           while ((directory = readdir(d)) != NULL) {
            if (directory->d_name[0] != '.') {
              char *sss = (directory->d_name);
                while(sss[z] != '\0') {
                  in_data.str_directory[num_dir][num_in_dir][z] = sss[z];
                  z++;
                }
              num_in_dir++;   
              z=0;
            }
          }
          //in_data.str_directory[num_dir][num_in_dir] = NULL; сегментейшн фолд
          num_in_dir = 0;
          num_dir++; 
          num++;
     }
}

my_bubble_sort_directory(argc);
num_dir = 1;
while(num_dir < argc) {
arr_with_space(in_data.str_directory[num_dir]);
num_dir++;
}
//выводит отсортированный массив с табами в каждой строке своими
// //////////////////////////////////////////
// num_dir = 0;
//   num_in_dir = 0;
//     while(num_dir < argc) {
//       while(in_data.str_directory[num_dir][num_in_dir] != NULL) {
//         printf("%s", in_data.str_directory[num_dir][num_in_dir]);
//         num_in_dir++;
//       }
//       printf("\n");
//       num_in_dir = 0;
//       num_dir++;
//      }
/////////////////////////////////////////////
closedir(d);
}
