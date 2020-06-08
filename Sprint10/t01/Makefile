NAME = mx_cp
SRC = *.c
INC = readfile.h
COMPILLER = -std=c11 -Wall -Wextra -Werror -Wpedantic
all: install clean
install:
	@cp inc/*.h .
	@cp src/*.c .
	@clang $(COMPILLER) -o $(NAME) *.c
uninstall: clean
	@rm -rf $(NAME)
clean:
	@rm -rf *.c
	@rm -rf *.h
reinstall: uninstall install
	@rm -rf *.c
	@rm -rf *.h

/*
DESCRIPTION
Create a program that:
• copies the contents of a source file to a new file
• does nothing if a destination file already exists
• prints the respective message to the stderr followed by a newline if a source file
does not exist
Tips for this task
1. The program is similar with the utility cp .
2. You do not need to process cp options.
3. Use the standard error for printing errors.
4. You can use errno if you know how.
CONSOLE OUTPUT
>./mx_cp src_file | cat -e
usage: ./mx_cp [source_file] [destination_file]
>cat -e src_file
cat: src_file: No such file or directory
>./mx_cp src_file dst_file | cat -e
mx_cp: src_file: No such file or directory
>echo "Matrix" > src_file
>cat -e src_file
Matrix$
>cat -e dst_file
cat: dst_file: No such file or directory
>./mx_cp src_file dst_file | cat -e
>cat -e dst_file
Matrix$
>
*/

