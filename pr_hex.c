//
// Created by Tania PYROGOVSKA on 7/24/18.
//

#include "ft_printf.h"

void	hex_num(unsigned int num, char *s, int i, int size, int X)
{
	int n;
	char c;

	if (X == 1)
		c = 'A';
	else
		c = 'a';
	while (size--)
	{
		n = (int)(num / ft_pow(16, size));
		if (n > 9)
			s[i] = n - 10 + c;
		else
			s[i] = n + '0';
		num %= ft_pow(16, size);
		i++;
	}
	s[i] = '\0';
}

char	*pr_hex(unsigned int num, int hash, int X)
{
	int i;
	int size;
	char *s;

	i = 0;
	size = count(num, 16);
	s = ft_strnew(size + 1);
	if (hash == 1 && X == 0)
	{
		s[i++] = '0';
		s[i++] = 'x';
	}
	else if (hash == 1 && X == 1)
	{
		s[i++] = '0';
		s[i++] = 'X';
	}
	hex_num(num, s, i, size, X);
	return (s);
}