NAME = mx_wc
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

