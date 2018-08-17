/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:46:09 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/13 14:46:10 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <locale.h>
# include "libft/includes/libft.h"

enum			e_ref{NONE, H, HH, L, LL, Z, J};

typedef struct	s_flags
{
	enum e_ref	ref;
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			precision;
	int			size;
	int 		cur;
}				t_flags;

int				ft_printf(char *format, ...);

t_flags			*init_flags();
char			*get_flags(char *format, t_flags *flags);
char			*get_ref(char *format, t_flags *flags);
void			apply_format(char **str, t_flags *flags);

char			*dec_type(va_list ap, t_flags *flags, int caps);
char			*octal_type(va_list ap, t_flags *flags, int caps);
char			*unsigned_type(va_list ap, t_flags *flags, int caps);
char			*hex_type(va_list ap, t_flags *flags, int p);

char			*put_nbr_base(intmax_t num, int base, t_flags *flags);
char			*put_unsigned_nbr(uintmax_t num, int base, t_flags *flags);

char			*str_out(char *s, t_flags *flags);
char			*put_char(char c, t_flags *flags);
char			*put_char_loc(wchar_t c, t_flags *flags);
char			*put_str_loc(wchar_t *s, t_flags *flags);

int				count(intmax_t x, int base);
int				u_count(uintmax_t x, int base);
uintmax_t		power(uintmax_t num, int power);
int				is_right(char c);
char			*to_upper(char *s);

void			plus(char **s);
void			zero(char **s, int width);
void			space(char **s, t_flags *flags);
void			hash(char **s, int hash);
void			minus(char **s, t_flags *flags);

int 			bit_count(unsigned int c);
void			ft_put_str(char *s, int size);
char			*ft_stradd(char *s1, char *s2, int size1, int size2);

char			*mask1(unsigned int c, t_flags *flags);
char			*mask2(unsigned int c, t_flags *flags);
char			*mask3(unsigned int c, t_flags *flags);
char 			*mask4(unsigned int c, t_flags *flags);

#endif
