//
// Created by Tania PYROGOVSKA on 8/14/18.
//

#include "ft_printf.h"

void	apply_format(char **str, t_flags *flags)
{
	if (flags->precision > 0)
		zero(str, flags->precision);
	if (flags->minus == 1)
		minus(str, flags);
	if (flags->space == 1)
		space(str, flags);
	if (flags->zero == 1)
		zero(str, flags->width);
}