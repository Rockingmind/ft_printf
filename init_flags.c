/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:46:33 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/13 14:46:34 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*init_flags(void)
{
	t_flags *flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->ref = NONE;
	flags->hash = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->space = 0;
	flags->size = 0;
	flags->size = 0;
	return (flags);
}

int		get_nums(char *format, t_flags *flags)
{
	int num;

	if (*format == '.')
	{
		format++;
		flags->precision = ft_atoi(format);
		num = ft_count_digits(flags->precision + 1);
	}
	else
	{
		flags->width = ft_atoi(format);
		num = ft_count_digits(flags->width) - 1;
	}
	return (num);
}

char	*get_ref(char *format, t_flags *flags)
{
	if (*format == 'h')
		if (*(format + 1) == 'h') {
			flags->ref = HH;
			format++;
		} else
			flags->ref = H;
	else if (*format == 'l')
		if (*(format + 1) == 'l')
		{
			flags->ref = LL;
			format++;
		}
		else
			flags->ref = L;
	else if (*format == 'z')
		flags->ref = Z;
	else if (*format == 'j')
		flags->ref = J;
	else
		return (format);
	format++;
	return (format);
}

char	*get_flags(char *format, t_flags *flags)
{
	while (*format != '\0')
	{
		if (*format == '#')
			flags->hash = 1;
		else if (*format == '+')
			flags->plus = 1;
		else if (*format == '-')
			flags->minus = 1;
		else if (*format == ' ')
			flags->space = 1;
		else if (*format == '0')
			flags->zero = 1;
		else if (ft_isdigit(*format) || *format == '.')
			format += get_nums(format, flags);
		else
			break ;
		format++;
	}
	return (get_ref(format, flags));
}
