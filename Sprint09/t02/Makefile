NAME = minilibmx.a
SRC = src/mx_atoi.c \
		src/mx_isdigit.c \
		src/mx_isspace.c \
		src/mx_printchar.c \
		src/mx_printint.c \
		src/mx_printstr.c \
		src/mx_strcmp.c \
		src/mx_strcpy.c\
		src/mx_strlen.c

SRC_IN = mx_atoi.c \
		mx_isdigit.c \
		mx_isspace.c \
		mx_printchar.c \
		mx_printint.c \
		mx_printstr.c \
		mx_strcmp.c \
		mx_strcpy.c\
		mx_strlen.c 

OBJ = mx_atoi.o \
		mx_isdigit.o \
		mx_isspace.o \
		mx_printchar.o \
		mx_printint.o \
		mx_printstr.o \
		mx_strcmp.o \
		mx_strcpy.o \
		mx_strlen.o 

INC = inc/header.h
INC_IN = header.h

COMPILLER = -std=c11 -Wall -Wextra -Werror -Wpedantic -c
all: MINILIBMX
MINILIBMX:
	@mkdir -p obj
	@cp $(INC) .
	@cp $(SRC) .
	@clang $(COMPILLER) $(SRC_IN)
	@ar rc $(NAME) $(OBJ)
	@mv $(OBJ) ./obj/
uninstall: clean
	@rm -rf $(NAME)
clean:
	@rm -rf $(SRC_IN)
	@rm -rf $(INC_IN)
	@rm -rf obj
reinstall: uninstall install
