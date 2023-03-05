##
## EPITECH PROJECT, 2022
## Makefile project
## File description:
## compile the project and the lib
##

SRC	= 	my_printf.c \
		flag_c.c \
		flag_d.c \
		flag_i.c \
		flag_o.c \
		flag_s.c \
		flag_f.c \
		flag_n.c \
		flag_e.c \
		flag_u.c \
		flag_x.c \
		flag_x_maj.c \
		flag_percentage.c \
		flag_f_maj.c \
		flag_e_maj.c \
		count_digit.c \
		find_flag.c \
		my_strlen.c \
		my_put_nbr.c \
		my_putchar.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libprintf.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../../include
	cp $(NAME) ../
	cp my.h ../../include


clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)
	rm -f ../$(NAME)

re: clean all

.PHONY: all clean fclean re
