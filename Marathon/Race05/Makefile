NAME = race05
 
INC = inc/minilibmx.h

SRC = src/rain.c

CFLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses

all: install clean
install:
	cp $(SRC) .
	cp $(INC) .
	clang $(CFLAG) -o $(NAME) $(SRC) -I inc
uninstall: clean
	rm -rf $(NAME)	
clean:
	rm -rf minilibmx.h
	rm -rf rain.c
reinstall: uninstall clean all

