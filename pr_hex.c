//
// Created by Tania PYROGOVSKA on 7/24/18.
//

#include "ft_printf.h"

int 	count_h(unsigned int num)
{
	int i;

	while ((num /= 16))
		i++;
	return (i + 1);
}

void	hex_num(unsigned int num, char *s, int i, int size)
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

char	*pr_hex(unsigned int num, int hash)
{
	int i;
	int size;
	char *s;

	i = 0;
	size = count_h(num);
	s = ft_strnew(size + 1);
	if (hash == 1)
	{
		s[i++] = '0';
		s[i++] = 'x';
	}
	hex_num(num, s, i, size);
	return (s);
}