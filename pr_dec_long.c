//
// Created by Tania PYROGOVSKA on 7/24/18.
//

#include "ft_printf.h"
#include <stdio.h>
int 	count_num(long num)
{
	int i;

	i = 0;
	while ((num /= 10))
		i++;
	return (i + 1);
}
char	*pr_dec_long(long num, int plus)
{
	char *s;
	int	i;
	int size;

	i = 0;
	size = count_num(num);
	if (plus == 1)
		size++;
	s = ft_strnew(size + 1);
	if (plus == 1)
	{
		if (num < 0) {
			s[i++] = '-';
			num *= -1;
		} else
			s[i++] = '+';
	}
	while (size--)
	{
		s[i] = (int)(num / ft_pow(10, size)) + '0';
		num %= ft_pow(10, size);
		i++;
	}
	s[i] = '\0';
	return (s);
}
