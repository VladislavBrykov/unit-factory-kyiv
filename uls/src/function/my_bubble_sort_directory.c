#include "uls.h"

static int x_strcmp(const char *s1, const char *s2) {
    while ((*s1 != '\0' || *s2 != '\0') && (*s1 == *s2)) {
        s1++;
        s2++;
    }   
    if (*s1 != *s2) {
        return *s1 - *s2;
    }
    else {
        return 0;
    }
}
////////////////////////////////////////////////////////////////
//сортировка по содержимому папок
void my_bubble_sort_directory(int argc) {
	char *kesh;
    int a = 0;
while(a < argc) {
	for (int i = 1; in_data.str_directory[a][i][0] != '\0'; i++) {
		for (int j = i + 1; in_data.str_directory[a][j][0] != '\0'; j++) {
			if (x_strcmp(in_data.str_directory[a][i], in_data.str_directory[a][j]) > 0) {
				kesh = in_data.str_directory[a][i];
				in_data.str_directory[a][i] = in_data.str_directory[a][j];
				in_data.str_directory[a][j] = kesh;
			}
		}
	}
a++;
}
///////////////////////////////////////////////////////////////////
///сортировка по папкам
  char **kesh_1;
int size = argc;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if ((mx_strcmp(*in_data.str_directory[i], *in_data.str_directory[j]) > 0) && ((*in_data.str_directory[i] != '\0') || (*in_data.str_directory[j] != '\0'))) {
        kesh_1 = in_data.str_directory[i];
        in_data.str_directory[i] = in_data.str_directory[j];
        in_data.str_directory[j] = kesh_1;
      }
    }
  }
///////////////////////////////////////////////////////////////////
    // int num_dir = 0;  //проверка перезаписанного трехмерного массива
    // int num_in_dir = 0;
    // while(num_dir < argc) {
    //   while(in_data.str_directory[num_dir][num_in_dir] != NULL) {
    //     printf("%s", in_data.str_directory[num_dir][num_in_dir]);
    //     printf("\t");
    //     num_in_dir++;
    //   }
    //   //printf("stroka");
    //   printf("\n");
    //   num_in_dir = 0;
    //   num_dir++;
    // }
}
