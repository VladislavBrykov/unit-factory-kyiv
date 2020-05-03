NAME = minilibmx.a
SRC_IN = src/mx_strlen.c src/mx_atoi.c src/mx_printstr.c src/mx_isspace.c src/mx_isdigit.c src/mx_printchar.c src/mx_strcmp.c src/mx_printint.c src/mx_strcpy.c
SRC_OBJEKTS = mx_strlen.c mx_atoi.c mx_printstr.c mx_isspace.c mx_isdigit.c mx_printchar.c mx_strcmp.c mx_printint.c mx_strcpy.c

INC = inc/minilibmx.h
INC_OBJEKTS = minilibmx.h
OBJ_INSTALL = obj/mx_strlen.o obj/mx_atoi.o obj/mx_printstr.o obj/mx_isspace.o obj/mx_isdigit.o obj/mx_printchar.o obj/mx_strcmp.o obj/mx_printint.o obj/mx_strcpy.o
MY_COMPILLER = -std=c11 -Wall -Wextra -Werror -Wpedantic
all: MINILIBMX
MINILIBMX:
	mkdir obj
	cp $(SRC_IN) obj/
	cp $(INC) obj/
	cd obj; clang $(MY_COMPILLER) -c $(SRC_OBJEKTS)
	ar rc $(NAME) $(OBJ_INSTALL)
	cd obj; rm $(SRC_OBJEKTS) $(INC_OBJEKTS)
reinstall: uninstall MINILIBMX all
uninstall: clean
	rm  $(NAME) obj/
clean:
	rm -rf obj


