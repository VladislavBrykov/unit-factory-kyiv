void mx_printchar(char c);
int mx_strlen(const char *s);
void mx_printstr(const char *s);

int main(int argc, char *argv[]) {
    for(int i = 1; i < argc; i++) {
	mx_printstr(argv[i]);
	mx_printchar('\n');
    }
    return 0;
}

//dla proverki kompilim
//./mx_print_args Follow the white rabbit | cat -e
//vidast argv s novih strok 
//Follow$
//the$
//white$
//rabbit$

