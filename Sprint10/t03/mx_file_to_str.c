#include "file_to_str.h"

char *mx_file_to_str(const char *filename){
	char buff;
	int length = 0;
	int i = 0;


	int file = open(filename, O_RDONLY);

	if (file == -1)
	{
		return NULL;
	}
	while(read(file, &buff, 1)){
		length++;
	}
	 close(file);

	file = open(filename, O_RDONLY);
	char *string = mx_strnew(length);
	while(read(file, &buff, 1)){
			string[i] = buff;
			i++;
	}
	close(file);
	return string;
}
int main()
{
	//char *result = mx_file_to_str("test_file");
	printf("%s\n", mx_file_to_str("mx_strnew.c"));
	system ("leaks -q test");
	return 0;
}
