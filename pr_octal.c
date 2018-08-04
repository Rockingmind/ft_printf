//
// Created by Tania PYROGOVSKA on 7/24/18.
//

#include "ft_printf.h"

int 	count(unsigned int num)
{
	int i;

	i = 0;
	while ((num /= 8))
		i++;
	return (i + 1);
}

char	*pr_octal(unsigned int num, int hash)
{
	int size;
	char *s;
	int i;

	i = 0;
	size = count(num);
	if (hash == 1)
		size++;
	s = ft_strnew(size + 1);
	while (size--)
	{
		s[i] = (int)(num / ft_pow(8, size)) + '0';
		num %= ft_pow(8, size);
		i++;
	}
	s[i] = '\0';
	return (s);
}