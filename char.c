//
// Created by Tania PYROGOVSKA on 8/8/18.
//

#include "ft_printf.h"

char	*char_int(signed char c)
{
	return (ft_itoa(c));
}

char	*char_unsigned(unsigned short int num)
{
	char *s;
	int size;
	int i;

	i = 0;
	size = count(num, 10);
	s = ft_strnew(size + 1);
	while (size--)
	{
		s[i++] = num / power(10, size) + '0';
		num %= power(10, size);
	}
	s[i] = '\0';
	return (s);
}

char	*char_octal(unsigned char num)
{
	char *s;
	int size;
	int i;

	i = 0;
	size = count(num, 8);
	s = ft_strnew(size);
	while (size--)
	{
		s[i++] = num / power(8, size) + '0';
		num %= power(8, size);
	}
	s[i] = '\0';
	return (s);
}

char	*char_hex(unsigned char num, int caps)
{
	char *mask;
	char *s;
	int i;
	int size;

	i = 0;
	if (caps == 1)
		mask = ft_strdup("0123456789ABCDEF");
	else
		mask = ft_strdup("0123456789abcdef");
	size = count(num, 16);
	s = ft_strnew(size + 1);
	while(size--)
	{
		s[i++] = mask[num / power(16, size)];
		num %= power(16, size);
	}
	s[i] = '\0';
	return (s);
}
