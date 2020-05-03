#include "readfile.h"

int main(int argc, char *argv[]) {
	char buff;
	int file1 = 0;
	int file2 = 0;
        if (argc != 3) {
                mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
		exit(1);
	}
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1) {
		mx_printerr("mx_cp: src_file: No such file or directory\n");
		close(file1);
		exit(1);
	}
	file2 = open(argv[2], O_CREAT | O_WRONLY, S_IWUSR | S_IRUSR);
	while(read(file1, &buff, 1)) {
		write(file2, &buff, 1);
	}  
	close(file1);
	close(file2);
	exit(0);
}
