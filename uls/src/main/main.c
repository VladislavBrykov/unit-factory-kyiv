#include "uls.h"

int main(int argc, char *argv[]) {
	int i = 1;
    
  if(argc > 1) {
    error_flag(argv[1]); 

    while(argv[i][0] == '-')
  	  i++;
    no_such_directory(argv[i]);
  }

  uls(argc, i, argv);

   //if(argc == 1)
   //uls_a(argv[i]);
   return 0;
    // system("leaks pathfinder");
}
