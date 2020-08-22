#include <stdlib.h>

int mx_count_words(const char *str, char delimiter);	//bydem ispolzovat
char *mx_strncpy(char *dst, const char *src, int len);	
char *mx_strnew(const int size);

char **mx_strsplit(char const *s, char c) {	//new function
    
    if (s == 0)		//stavim uslovie
        return 0;

    int massiv = mx_count_words(s, c);  //sozdaem massiv

    char **result = (char **) malloc(sizeof(char *) * (massiv + 1)); //videlaem pamat
    result[massiv] = 0;

    for (int p = 0; p < massiv; p++) { //yslovie
        while (*s == c) {		//ispolzyem cicl while
            s++;
        }
        char *peremennaia = (char *) s;
        int dlina = 0;			//obiavlaem peremennyu dlina
        while (*s != c) {		//ispolzyem cicl while
            dlina++;
            s++;
        }

        char *word = mx_strnew(dlina);
        mx_strncpy(word, peremennaia, dlina);
        result[p] = word;
    }

    return result;
}
