#include <stdlib.h>

void mx_del_strarr(char ***arr) {	//new function
    for (int b = 0; (*arr)[b]; b++) {	//zapuskaem cicl for
        free((*arr)[b]);  		//chistim pamiat
    }
    free(*arr);				//chistim pamiat
    *arr = NULL;			//cbros na NULL
}
