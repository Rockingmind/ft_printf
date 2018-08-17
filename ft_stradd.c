//
// Created by Tania PYROGOVSKA on 8/17/18.
//

#include "ft_printf.h"

int 	bit_count(unsigned int c)
{
	int i;

	i = 0;
	while ((c = c >> 1))
		i++;
	return (i + 1);
}

char	*ft_stradd(char *s1, char *s2, int size1, int size2)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strnew(size1 + size2);
	while (i < size1)
	{
		s[i] = *s1;
		s1++;
		i++;
	}
	while (i < size1 + size2)
	{
		s[i] = *s2;
		s2++;
		i++;
	}
	return (s);
}

void	ft_put_str(char *s, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		write(1, s, 1);
		i++;
		s++;
	}
}
