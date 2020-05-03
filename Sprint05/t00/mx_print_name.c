#include <unistd.h>
  
void mx_printchar(char c);
int mx_strlen(const char *s);
void mx_printstr(const char*s);
void mx_printint(int n);

int main (int argc, char *argv[]) {
    mx_printstr(argv[0]);
    mx_printchar('\n');
    mx_printint(argc);
    mx_printchar('\n');
}

//dla zapuska kompilim i vvodim
//./mx_print_name Follow the white rabbit | cat -e
//vidim argv[0] i args
//./mx_print_name$
//5$
