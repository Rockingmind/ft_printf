/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:45:52 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/13 14:45:55 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_spec(va_list ap, char *str, t_flags *flags)
{
	if (*str == 's')
		return (str_out(va_arg(ap, char *), flags));
	else if (*str == 'S')
		return (put_str_loc(va_arg(ap, wchar_t *), flags));
	else if (*str == 'c')
		return (put_char((char)va_arg(ap, int), flags));
	else if (*str == 'C')
		return (put_char_loc(va_arg(ap, wchar_t), flags));
	else if (*str == 'p')
		return (hex_type(ap, flags, 1));
	else if (*str == 'O')
		return (octal_type(ap, flags, 1));
	else if (*str == 'U')
		return (unsigned_type(ap, flags, 1));
	else
		return (put_char(*str, flags));
}

char	*find_type(va_list ap, char *str, t_flags *flags)
{
	if (*str == 'd' || *str == 'i')
		return (dec_type(ap, flags, 0));
	else if (*str == 'D')
		return (dec_type(ap, flags, 1));
	else if (*str == 'o')
		return (octal_type(ap, flags, 0));
	else if (*str == 'u')
		return (unsigned_type(ap, flags, 0));
	else if (*str == 'x')
		return (hex_type(ap, flags, 0));
	else if (*str == 'X')
		return (to_upper(hex_type(ap, flags, 0)));
	else
		return (get_spec(ap, str, flags));
}

int		process(va_list ap, char *format, char **res, t_flags *flags)
{
	char *add;
	char *save;
	char *str;

	save = ft_strdup(*res);
	free(*res);
	str = get_flags(format + 1, flags);
	add = find_type(ap, str, flags);
	apply_format(&add, flags);
	*res = ft_stradd(save, add, flags->size, flags->cur);
	flags->size += flags->cur;
	return (ft_strlen(format) - ft_strlen(str));
}

int		ft_printf(char *format, ...)
{
	va_list	ap;
	t_flags	*flags;
	char	*result;
	int		i;

	i = 0;
	flags = init_flags();
	result = ft_strnew(ft_strlen(format));
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += process(ap, format + i, &result, flags);
		else
		{
			result[flags->size] = format[i];
			flags->size++;
		}
		i++;
	}
	va_end(ap);
	ft_put_str(result, flags->size);
	return (flags->size);
}
