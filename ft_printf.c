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
	if (*str == 's' && flags->ref != L)
		return (str_out(va_arg(ap, char *), flags));
	else if (*str == 'S' || (*str == 's' && flags->ref == L))
		return (put_str_loc(va_arg(ap, wchar_t *), flags));
	else if (*str == 'C' || (*str == 'c' && flags->ref == L))
		return (put_char_loc(va_arg(ap, wchar_t), flags));
	else if (*str == 'c')
		return (put_char((char)va_arg(ap, int), flags));
	else if (*str == 'p')
		return (hex_type(ap, flags, 1));
	else if (*str == 'O')
		return (octal_type(ap, flags, 1));
	else if (*str == 'U')
		return (unsigned_type(ap, flags, 1));
	else if (*str == '%')
		return (per(flags));
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

void	spec(t_flags *flags, char ch)
{
	if (ch == 'd' || ch == 'D')
		flags->spec = d;
	else if (ch == 'o' || ch == 'O')
		flags->spec = o;
	else if (ch == 'x')
		flags->spec = x;
	else if (ch == 'u' || ch == 'U')
		flags->spec = u;
	else if (ch == 'c' || ch == 'C')
		flags->spec = c;
	else if (ch == 's' || ch == 'S')
		flags->spec = s;
	else if (ch == '%')
		flags->spec = pc;
	else if (ch == 'p')
		flags->spec = p;
	else if (ch == 'i')
		flags->spec = i;
	else if (ch == 'X')
		flags->spec = xcaps;
}

int		process(va_list ap, char *format, char **res, int *size)
{
	char *add;
	char *save;
	char *str;
	t_flags *flags;

	flags = init_flags();
	save = ft_strdup(*res);
	free(*res);
	str = get_flags(format + 1, flags);
	spec(flags, *str);
	add = find_type(ap, str, flags);
	if (flags->spec == s)
		change_str(&add, flags);
	else
		apply_format(&add, flags);
	*res = ft_stradd(save, add, *size, flags->cur);
	*size += flags->cur;
	free(save);
	free(add);
	free_flags(flags);
	return (ft_strlen(format) - ft_strlen(str));
}

int		ft_printf(char *format, ...)
{
	va_list	ap;
	int		*size;
	char	*result;
	int		i;

	i = 0;
	size = (int *)malloc(sizeof(int) * 1);
	*size = 0;
	result = ft_strnew(ft_strlen(format));
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += process(ap, format + i, &result, size);
		else
		{
			result[*size] = format[i];
			(*size)++;
		}
		i++;
	}
	va_end(ap);
	ft_put_str(result, *size);
	free(result);
	return (*size);
}
