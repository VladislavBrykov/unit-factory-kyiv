#include <stdbool.h>

bool mx_isdigit(int c);
void mx_printint(int n);
int mx_atoi(const char *str);
void mx_printchar(char c);
int mx_strlen(const char *s);

static int str_len(char *s) {
    int i = 0;

    while (s[i])
        i++;
    return i;
}

static int is_num(char *s) {
    int i = 0;

    if (s[0] == '-' || s[0] == '+')
        i++;
    while (i < str_len(s)) {
        if (mx_isdigit(s[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int sum = 0;

    for (int i = 1; i < argc; i++) {
        if (is_num(argv[i]))
            sum += mx_atoi(argv[i]);
    }
    mx_printint(sum);
    mx_printchar('\n');
}

//kompilim
//>./mx_sum_args 1- -7 | cat -e
//-7$
//./mx_sum_args a1 b 2 c-3 | cat -e
//2$
//>./mx_sum_args 1 "  2" "3" "10 " | cat -e
//4$
//./mx_sum_args 1 +2 -3 +-4 5+ 6at "  7" | cat -e
//0$
//./mx_sum_args a1 2- | cat -e
//0$
