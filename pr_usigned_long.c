//
// Created by Tania PYROGOVSKA on 8/4/18.
//

#include "ft_printf.h"
#include <stdio.h>

int 	count_un_l(unsigned long num)
{
	int i;

	i = 0;
	while (num /= 10)
		i++;
	return (i + 1);
}

char	*pr_unsigned_long(unsigned long num)
{
	int i;
	int size;
	char *s;

	size = count_un_l(num);
	i = size;
	s = ft_strnew(size + 1);
	while (i--)
	{
		s[i] = (int)(num % 10) + '0';
		num /= 10;
	}
	s[size] = '\0';
	return (s);
}