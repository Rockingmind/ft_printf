//
// Created by Tania PYROGOVSKA on 7/24/18.
//

#include "ft_printf.h"

int 	suitable(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

void	manage_format(t_flags *flags, char **str)
{
	if (flags->minus == 1 && (int)ft_strlen(*str) < flags->min_width)
		fl_minus(flags, str);
	if (flags->zero == 1 && (int)ft_strlen(*str) < flags->min_width)
		fl_zero(flags, str);
	if (flags->precision > 0)
		fl_zero(flags, str);
	if (flags->minus == 0 && (int)ft_strlen(*str) < flags->min_width && flags->space == 0)
		right_align(flags, str);
	if (flags->space == 1 && (int)ft_strlen(*str) < flags->min_width)
		right_align(flags, str);
	if (flags->plus == 1)
		plus(str);
}
