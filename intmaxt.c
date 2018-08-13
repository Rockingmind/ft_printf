//
// Created by Tania PYROGOVSKA on 8/8/18.
//

#include "ft_printf.h"

char	*intmaxt_int(intmax_t num)
{
	int i;
	int size;
	char *s;

	i = 0;
	size = count(num, 10);
	if (num < 0)
		size++;
	s = ft_strnew(size + 1);
	if (num < 0)
	{
		s[i++] = '-';
		num *= -1;
		size--;
	}
	while (size--)
	{
		s[i++] = num / power(10, size) + '0';
		num %= power(10, size);
	}
	s[i] = '\0';
	return (s);
}

char	*intmaxt_unsign(uintmax_t num)
{
	int i;
	int size;
	char *s;

	i = 0;
	size = u_count(num, 10);
	s = ft_strnew(size + 1);
	while (size--)
	{
		s[i++] = num / u_power(10, size) + '0';
		num %= u_power(10, size);
	}
	s[i] = '\0';
	return (s);
}

char	*intmaxt_octal(uintmax_t num)
{
	char *s;
	int size;
	int i;

	i = 0;
	size = u_count(num, 8);
	s = ft_strnew(size + 1);
	while (size--)
	{
		s[i++] = num / u_power(8, size) + '0';
		num %= u_power(8, size);
	}
	s[i] = '\0';
	return (s);
}

char *intmaxt_hex(uintmax_t num, int caps)
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
