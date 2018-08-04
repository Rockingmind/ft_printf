//
// Created by Tania PYROGOVSKA on 7/20/18.
//

#ifndef PRINTF_TRUE_PRINTF_H
#define PRINTF_TRUE_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <locale.h>
#include "libft/includes/libft.h"

typedef struct		s_flags{
	int 			min_width;
	int 			precision;
	int 			hash;
	int 			zero;
	int 			minus;
	int 			space;
	int 			plus;
	int 			H;
	int 			HH;
	int 			L;
	int 			LL;
	int				J;
	int 			Z;
}					t_flags;

int			ft_printf(char *format, ...);
t_flags		*init_flags();
char		*width_format(t_flags **flags, char *s);

//spec
char		*pr_dec(int num, int plus);
char		*pr_char(char c);
char		*pr_string(char *s);
char		*pr_dec_long(long num, int plus);
char		*pr_octal(unsigned int num, int hash);
char		*pr_hex(unsigned int num, int hash);
char		*pr_unsigned_int(unsigned int num);
char		*pr_addr(long p);

//flags
void		manage_format(t_flags *flags, char **str);
void		fl_minus(t_flags *flags, char **str);
void		fl_zero(t_flags *flags, char **str);
void 		right_align(t_flags *flags, char **str);

#endif //PRINTF_TRUE_PRINTF_H
