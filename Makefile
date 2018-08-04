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
INCL_LIB= ./libft/includes/%.h
OBJ= $(SRC:.c=.o)
SRC_LIB= ./libft/*.c
OBJ_LIB= $(SRC_LIB:.c=.o)
NAME= libftprintf

all: $(NAME)


$(NAME): $(OBJ_LIB) $(OBJ)
	ar rc libftprintf.a $(OBJ) $(OBJ_LIB)
	ranlib libftprintf.a

$(OBJ_LIB): %.o: %.c
	$(CC) ${CFLAGS} -I=${INCL_LIB} -c $< -o $@ 

$(OBJ): %.o: %.c
	$(CC) ${CFLAGS} -I=${INCL} -c $< -o $@ 

clean:
	rm -f *.o
	rm -f libft/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
