#include "mx_wc.h"
​
int main(int argc, char const *argv[]) {
	char buff;
	int lines = 0, words = 0, characters = 0;
	int total_lines = 0, total_words = 0, total_char = 0;
	int isinword = 0; //whether counter in word or not
//...counting of input. if only program name
if (argc == 1) {
	while (read(0, &buff, 1)) {
		for (int i = 0; i < argc; i++) {
			if (buff == '\n') {
				lines++;
				isinword = 0;
			}
			else if (buff == ' ' || buff == '\t' || buff == '\n') {
				isinword = 0;
			}
			else if (isinword == 0) {
				isinword = 1;
				words++;
			}
		characters++;
		}
	}
	mx_printchar('\t');
	mx_printint(words);
	mx_printchar('\t');
	mx_printint(lines);
	mx_printchar('\t');
	mx_printint(characters);
	mx_printchar('\n');
	return 0;
}
//...counting inside files
else {
	for (int f = 1; f < argc; f++) {
		char *files = mx_file_to_str(argv[f]);
			if (files == NULL) {
				mx_printerr("mx_wc: ");
				mx_printerr(argv[f]);
				mx_printerr(": open: No such file or directory\n");
			}
		for (int i = 0; files[i] != '\0'; i++) {
			if (files[i]) {
				lines++;
			}
			characters++;
		}
		words = mx_count_words(files);
​
			mx_printchar('\t');
			mx_printint(words);
			mx_printchar('\t');
			mx_printint(lines);
			mx_printchar('\t');
			mx_printint(characters);
			mx_printchar('\t');
			mx_printstr(argv[f]);
			mx_printchar('\n');
	
		total_words += words;
		total_lines += lines;
		total_char += characters;
​
		// lines = 0;
		// words = 0;
		// characters = 0;
		}
			mx_printchar('\t');
			mx_printint(total_lines);
			mx_printchar('\t');
			mx_printint(total_words);
			mx_printchar('\t');
			mx_printint(total_char);
			mx_printchar('\t');
			mx_printstr("total");
			mx_printchar('\n');
	}
	return 0;
}
