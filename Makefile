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
SRC=./flags.c \
	./ft_printf.c \
	./init_flags.c \
	./helpers.c \
	./put_nbr_base.c \
	./types.c \
	./print_characters.c \
	./apply_format.c
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
	rm -f ./libft/libft.a

re: fclean all
