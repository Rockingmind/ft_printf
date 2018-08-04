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
	./right_align.c \
	./libft/ft_strlen.c \
	./libft/ft_count_digits.c \
	./libft/ft_putstr.c \
	./libft/ft_strnew.c \
	./libft/ft_isdigit.c \
	./libft/ft_strdup.c \
	./libft/ft_strjoin.c \
	./libft/ft_fill_new.c \
	./libft/ft_writetil.c \
	./libft/ft_atoi.c \
	./libft/ft_bzero.c \
	./libft/ft_pow.c \
	./libft/ft_putchar.c \
	./libft/ft_strcat.c \
	./libft/ft_strcpy.c \
	./libft/ft_itoa.c \
	./libft/ft_isspace.c \
	./libft/ft_memset.c
INCL=./ft_printf.h
INCL_LIB= ./libft/includes/libft.h
OBJ= $(SRC:.c=.o)
NAME= libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	# make -C libft/ fclean && make -C libft/
	# cp libft/libft.a $(NAME)
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
