NAME = minilibmx.a
 
INC = minilibmx.h

SRC = mx_atoi.c mx_strlen.c mx_printstr.c mx_isdigit.c mx_isspace.c mx_printchar.c mx_printint.c mx_strcmp.c mx_strcpy.c

OBJ = $(SRC:.c=.o)

CFLAG = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: MINILIBMX

MINILIBMX:
	mkdir obj
	cp $(addprefix src/, $(SRC)) $(addprefix inc/, $(INC)) .
	clang $(CFLAG) -c $(SRC) -I $(INC)
	ar -rc $(NAME) $(OBJ)
	rm $(SRC) $(INC)
	mv $(OBJ) ./obj

uninstall:
	rm -rf $(NAME) obj/

clean:
	rm -rf obj/

reinstall: uninstall all

