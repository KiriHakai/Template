##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## A template Makefile
##

CC = gcc

SRC	=	tools/comparison/comp.c \
		tools/output/output.c \
		tools/output/mini_printf.c \
		tools/str_manip/str_manip1.c \
		tools/str_manip/str_manip2.c \
		tools/str_manip/my_str_to_tab.c \
		tools/str_manip/my_str_to_word_array.c \

MAIN	=	src/main.c

FLAGS	=

TESTS	=	tests/unit_tests.c

T_FLAGS	=	--coverage -lcriterion

NAME	= test

IGNORE	=	.gitignore'\n'\
			*.log '\n'\
			*~'\n'\
			*.out'\n'\
			$(NAME)'\n'\
			vgcore*'\n'\
			unit_tests\

all:	build clean

build:
	$(CC) $(MAIN) $(SRC) -o $(NAME) $(FLAGS)

clean:
	rm -f unit_tests
	rm -f *~
	rm -f vgcore*
	rm -f *.log

fclean: clean
	rm -f $(NAME)

re:	fclean all

val: $(CC) $(MAIN) $(SRC) -o $(NAME) $(FLAGS) -g3

unit_tests: fclean build
	$(CC) $(SRC) $(TESTS) -o unit_tests $(T_FLAGS)

tests_run: unit_tests
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

ignore:
	echo -e $(IGNORE) > .gitignore
