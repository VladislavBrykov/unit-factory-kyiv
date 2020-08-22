NAME = race03

SRCS = src/mx_atoi.c src/mx_insertion_sort.c src/mx_isdigit.c src/mx_is_duplicate.c \
		src/mx_isspace.c src/mx_printstr.c src/mx_strcmp.c src/mx_strdel.c src/mx_strlen.c \
		src/mx_strncpy.c src/mx_strnew.c src/mx_is_space.c src/mx_strndup.c src/mx_strtrim.c \
		src/mx_printerr.c src/mx_is_rank.c src/mx_is_suit.c src/mx_is_valid.c src/mx_is_flush.c \
		src/mx_is_kare.c src/mx_is_set.c src/mx_is_street.c src/mx_to_int.c src/mx_to_char.c \
		src/mx_pairs.c src/mx_sort.c src/mx_result.c src/main.c 

SRCSOB = mx_atoi.c mx_insertion_sort.c mx_isdigit.c mx_is_duplicate.c \
		mx_isspace.c mx_printstr.c mx_strcmp.c mx_strdel.c mx_strlen.c \
		mx_strncpy.c mx_strnew.c mx_is_space.c mx_strndup.c mx_strtrim.c \
		mx_printerr.c mx_is_rank.c mx_is_suit.c mx_is_valid.c mx_is_flush.c \
		mx_is_kare.c mx_is_set.c mx_is_street.c mx_to_int.c mx_to_char.c \
		mx_pairs.c mx_sort.c mx_result.c main.c

INC = inc/header.h
INCOB = header.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean
install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) $(SRCSOB) -I $(INCOB)
uninstall: clean
	@rm -rf $(NAME)
clean:
	@rm -rf $(INCOB)
	@rm -rf $(SRCSOB)
reinstall: uninstall clean all
