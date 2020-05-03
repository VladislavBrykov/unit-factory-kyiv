int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);
void mx_printstr(const char *s);
void mx_printchar(char c);

int main(int argc, char *argv[]) {

	for(int i = 1; i < argc; i++) {
		for(int j = 1; j < argc-i; j++) {
			if(mx_strcmp(argv[j], argv[j+1]) > 0){
				char *papka = argv[j];
				argv[j] = argv[j+1];
				argv[j+1] = papka;
			}
		}
	}

	for(int i = 1; i < argc; i++){
		mx_printstr(argv[i]);
		mx_printchar('\n');
	}

	return 0;
}

//kompilim
//./mx_print_sargs Follow the white rabbit |cat -e
//vidats
//Follow$
//rabbit$
//the$
//white$
