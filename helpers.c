//
// Created by Tania PYROGOVSKA on 8/13/18.
//

#include "ft_printf.h"

int			count(intmax_t x, int base)
{
	int res;

	res = 0;
	while (x /= base)
		res++;
	return (res + 1);
}

int			u_count(uintmax_t x, int base)
{
	int res;

	res = 0;
	while (x /= base)
		res++;
	return (res + 1);
}

uintmax_t	power(uintmax_t num, int power)
{
	uintmax_t res;

	res =  1;
	while (power--)
		res *= num;
	return (res);
}

char	*to_upper(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}

