//
// Created by Tania PYROGOVSKA on 7/24/18.
//

#include "ft_printf.h"

int 	coun(unsigned int num)
{
	int i;

	i = 0;
	while ((num /= 16))
		i++;
	return (i + 1);
}

void	hex(unsigned int num, char *s, int i, int size)
{
	int n;

	while (size--)
	{
		n = (int)(num / ft_pow(16,size));
		if (n > 9)
			s[i] = n - 10 + 'a';
		else
			s[i] = n + '0';
		num %= ft_pow(16, size);
		i++;
	}
	s[i] = '\0';
}

char	*pr_addr(long p)
{
	int i;
	int size;
	char *result;

	i = 0;
	size = coun(p);
	result = ft_strnew(size + 3);
	result[i++] = '0';
	result[i++] = 'x';
	hex(p, result, i, size);
	return (result);
}