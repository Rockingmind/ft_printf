//
// Created by Tania PYROGOVSKA on 7/24/18.
//

#include "ft_printf.h"

char	*pr_char(char c)
{
	char *s;

	s = ft_strnew(2);
	s[0] = c;
	s[1] = '\0';
	return (s);
}