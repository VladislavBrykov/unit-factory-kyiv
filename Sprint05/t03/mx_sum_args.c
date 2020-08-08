#include <stdbool.h>

bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printint(char n);
int mx_atoi(const char *str);
void mx_printchar(char c);


int main(int argc, char *argv[]) {
	int sum = 0;
	int num = 1;
	int i = 0;
   
	while(argv[num]) {
		if((argv[num][i] && argv[num][lenght -1]) == '"')
			i++; 
	for(int num = 1; num < argc; num++) {
		sum = sum + mx_atoi(argv[num]);
	}
	mx_printint(sum);
	return 0;
}
		
