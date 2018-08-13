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

int					ft_printf(char *format, ...);
t_flags				*init_flags();
char				*width_format(t_flags **flags, char *s);
char				*make_string(t_flags *flags, char s, va_list ap);

//spec
char				*pr_char(char c);
char				*pr_string(char *s);
char				*pr_dec_long(long num, int plus);
char				*pr_octal(unsigned int num, int hash);
char				*pr_hex(unsigned int num, int hash, int X);
char				*pr_unsigned_int(unsigned int num);
char				*pr_addr(long p);
char				*pr_octal_long(unsigned long num, int hash);
char				*pr_unsigned_long(unsigned long num);
char				*pr_char_locale(char c);

//flags
void				manage_format(t_flags *flags, char **str);
void				fl_minus(t_flags *flags, char **str);
void				fl_zero(t_flags *flags, char **str);
void 				right_align(t_flags *flags, char **str);
void	plus(char **str);

char				*dec_type(va_list ap, t_flags *flags);
char				*unsigned_type(va_list ap, t_flags *flags);
char				*octal_type(va_list ap, t_flags *flags);
char				*hex_type(va_list ap, t_flags *flags, int caps);

//helpers
int					count(size_t num, int base);
size_t				power(size_t num, int pow);
int					u_count(intmax_t num, int base);
intmax_t			u_power(intmax_t num, int pow);

char				*short_int(short int i);
char				*char_int(signed char c);
char				*long_int(long int num);
char				*long_long_int(long long int num);
char				*sizet_int(intmax_t num);
char				*intmaxt_int(intmax_t num);

char				*char_unsigned(unsigned short int num);
char				*short_usigned(unsigned short int num);
char				*long_unsigned(unsigned long int num);
char				*long_long_unsign(unsigned long long int num);
char				*sizet_unsign(size_t num);
char				*intmaxt_unsign(uintmax_t num);

char				*short_octal(unsigned short int num);
char				*char_octal(unsigned char num);
char				*long_octal(unsigned long int num);
char				*long_long_octal(unsigned long long int num);
char				*sizet_octal(size_t num);
char				*intmaxt_octal(uintmax_t num);

char				*char_hex(unsigned char num, int caps);
char				*short_hex(unsigned short int num, int caps);
char				*long_hex(unsigned long int num, int caps);
char				*long_long_hex(unsigned long long int num, int caps);
char				*sizet_hex(size_t num, int caps);
char				*intmaxt_hex(uintmax_t num, int caps);

#endif //PRINTF_TRUE_PRINTF_H
