//
// Created by Tania PYROGOVSKA on 7/20/18.
//

#include "ft_printf.h"

t_flags *init_flags()
{
	t_flags *new;

	new = (t_flags *)malloc(sizeof(t_flags));
	new->H = 0;
	new->HH = 0;
	new->L = 0;
	new->LL = 0;
	new->hash = 0;
	new->minus = 0;
	new->min_width = 0;
	new->precision = 0;
	new->zero = 0;
	new->space = 0;
	new->plus = 0;
	new->J = 0;
	new->Z = 0;
	return (new);
}

int		numbers(t_flags **flags, char *s)
{
	if (ft_isdigit(*s))
	{
		(*flags)->min_width = ft_atoi(s);
		return (ft_count_digits((*flags)->min_width) - 1);
	}
	else if (*s == '.')
	{
		s++;
		(*flags)->precision = ft_atoi(s);
		return (ft_count_digits((*flags)->precision));
	}
}

char	*type_flag(t_flags **flags, char *s)
{
	while (*s != '%' && *s != '\0')
	{
		if (*s == 'h')
			if (*(s + 1) == 'h')
			{
				(*flags)->HH = 1;
				s++;
			}
			else
				(*flags)->H = 1;
		else if (*s == 'l')
			if (*(s + 1) == 'l')
			{
				(*flags)->LL = 1;
				s++;
			}
			else
				(*flags)->L = 1;
		else if (*s == 'j')
			(*flags)->J = 1;
		else if (*s == 'z')
			(*flags)->Z = 1;
		else
			break;
		s++;
	}
	return (s);
}

char	*width_format(t_flags **flags, char *s)
{
	while (*s != '%' && *s != '\0')
	{
		if (*s == '-')
			(*flags)->minus = 1;
		else if (*s == '#')
			(*flags)->hash = 1;
		else if (*s == '+')
			(*flags)->plus = 1;
		else if (*s == '0' && !ft_isdigit(*(s - 1)))
			(*flags)->zero = 1;
		else if (ft_isdigit(*s) || *s == '.')
			s += numbers(flags, s);
		else if (*s == ' ' && *(s-1) == '%')
			(*flags)->space = 1;
		else
			break ;
		s++;
	}
	return (type_flag(flags, s));
}