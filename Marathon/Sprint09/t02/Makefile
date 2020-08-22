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

SRC_IN = *.c

OBJ = *.o

INC = inc/header.h
INC_IN = *.h

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
