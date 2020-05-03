NAME = race04

INC = ./inc/header.h
INCOBJ = header.h

SRC = ./src/main.c ./src/mx_printerr.c ./src/mx_strlen.c ./src/mx_printchar.c ./src/mx_printstr.c ./src/mx_isdigit.c ./src/mx_atoi.c ./src/mx_isspace.c ./src/mx_printint.c ./src/mx_strcmp.c
SRCOBJ = main.c mx_printerr.c mx_strlen.c mx_printchar.c mx_printstr.c mx_atoi.c mx_isdigit.c mx_isspace.c mx_printint.c mx_strcmp.c

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean
install:
	@cp $(INC) .
	@cp $(SRC) .
	@clang $(CFLAGS) -o $(NAME) $(SRCOBJ) -I $(INCOBJ)
uninstall: clean
	@rm -rf $(NAME)
clean:
	@rm -rf $(INCOBJ)
	@rm -rf $(SRCOBJ)
reinstall: uninstall clean all