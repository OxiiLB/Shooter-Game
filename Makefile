##
## EPITECH PROJECT, 2022
## Makefile project
## File description:
## compile the project and the lib
##

SRC	= 	main.c \
		src/my_hunter.c \
		src/error.c \
		src/destroy.c \
		src/window.c \
		src/event_handling.c \
		src/sprite.c \
		src/my_strncmp.c \
		src/checking_text.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	=	-Wall -Wextra  #-Werror

LDFLAGS	=	-L./lib

LDLIBS	=	-lprintf

CPPFLAGS	=	-I./include/ -ggdb3

LIB	=	lib/libprintf.a

all:	$(LIB) $(NAME)

$(LIB):
	make -C lib/my/
	make clean -C lib/my/

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) \
	-l csfml-graphics -l csfml-system


clean:
	make clean -C lib/my/
	rm -rf $(OBJ)

fclean:	clean
	make fclean -C lib/my/
	rm -rf $(NAME)

re: fclean all

tests_run: $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	gcc -o unit_tests cat.c ../tests/test_cat.c $(CPPFLAGS) $(LDFLAGS)
	$(LDLIBS) --coverage -lcriterion
	./unit_tests

.PHONY: all clean fclean re
