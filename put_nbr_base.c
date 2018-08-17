//
// Created by Tania PYROGOVSKA on 8/13/18.
//

#include "ft_printf.h"

char	*put_nbr_base(intmax_t num, int base, t_flags *flags)
{
	int 	size;
	int 	i;
	char	*res;
	char	*mask;

	i = 0;
	size = count(num, base);
	if (num < 0)
		size++;
	flags->cur = size;
	res = ft_strnew(size);
	mask = ft_strdup("0123456789abcdef");
	if (num < 0)
	{
		res[i++] = '-';
		num *= -1;
		size--;
	}
	while (size--)
	{
		res[i++] = mask[num / power(base, size)];
		num %= power(base, size);
	}
	return (res);
}

char	*put_unsigned_nbr(uintmax_t num, int base, t_flags *flags)
{
	int 	size;
	int 	i;
	char	*res;
	char	*mask;

	i = 0;
	size = u_count(num, base);
	flags->cur = size;
	res = ft_strnew(size);
	mask = ft_strdup("0123456789abcdef");
	while (size--)
	{
		res[i++] = mask[num / power(base, size)];
		num %= power(base, size);
	}

	return (res);
}