#include "uls.h"

int saearch_arguments(int argc, char **name) {
    int j = 1;
    int number = false;

    for ( ; j < argc; j++) {

        if (argc == 1)   //только название програмы
            number = 1;

        if ((name[j][0] == '-') && (name[j+1] == NULL)) {  //только флаг/флаги
            number = 2;
            break;
        }

        if (name[j][0] != '-') {   //только папка
            number = 3;
            break;
        }

        if ((name[j][0] == '-') && (name[j+1][0] != '-')) {  //флаг + дир
            number = 4;
            break;
        }

    }
    return number;
}
