#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 21:56:04 by tpyrogov          #+#    #+#              #
#    Updated: 2017/10/31 23:00:55 by tpyrogov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CFLGS= -Wall -Wextra -Werror
SRC=./fl_minus.c \
	./fl_zero.c \
	./flags.c \
	./ft_printf.c \
	./initialize.c \
	./pr_addr.c \
	./pr_char.c \
	./pr_dec.c \
	./pr_dec_long.c \
	./pr_hex.c \
	./pr_octal.c \
	./pr_string.c \
	./pr_unsigned_int.c \
	./right_align.c
INCL=./ft_printf.h
INCL_LIB= ./libft/includes/libft.h
OBJ= $(SRC:.c=.o)
NAME= libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/ fclean && make -C libft/
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ):%.o: %.c
	$(CC) ${CFLAGS} -I=${INCL} -c $< -o $@ 

clean:
	rm -f *.o
	rm -f ./libft/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
