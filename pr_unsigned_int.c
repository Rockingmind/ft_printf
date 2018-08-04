//
// Created by Tania PYROGOVSKA on 7/24/18.
//

#include "ft_printf.h"

int 	count_unsign(unsigned int num)
{
	int i;

	i = 0;
	while (num /= 10)
		i++;
	return (i + 1);
}

char	*pr_unsigned_int(unsigned int num)
{
	int i;
	int size;
	char *s;

	i = 0;
	size = count_unsign(num);
	s = ft_strnew(size + 1);
	while (size--)
	{
		s[i] = (int)(num / ft_pow(10, size)) + '0';
		num %= ft_pow(10, size);
		i++;
	}
	s[i] = '\0';
	return (s);
}