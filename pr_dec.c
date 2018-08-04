//
// Created by Tania PYROGOVSKA on 7/24/18.
//

#include "ft_printf.h"

char	*pr_dec(int num, int plus)
{
	if (plus == 1 && num > 0)
		return (ft_strjoin("+",ft_itoa(num)));
	return (ft_itoa(num));
}