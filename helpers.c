//
// Created by Tania PYROGOVSKA on 8/4/18.
//

#include "ft_printf.h"

int		count(size_t num, int base)
{
	int i;

	i = 0;
	while ((num /= base))
		i++;
	return (i + 1);
}

size_t	power(size_t num, int pow)
{
	size_t res;

	res = 1;
	while (pow--)
		res *= num;
	return (res);
}

int		u_count(intmax_t num, int base)
{
	int i;

	i = 0;
	while ((num /= base))
		i++;
	return (i + 1);
}

intmax_t	u_power(intmax_t num, int pow)
{
	size_t res;

	res = 1;
	while (pow--)
		res *= num;
	return (res);
}