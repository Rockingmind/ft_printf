//
// Created by Tania PYROGOVSKA on 7/20/18.
//

#include "ft_printf.h"

char	*other_types(t_flags *flags, char s, va_list ap)
{
	char *str;

	if (s == 'o')
		return (octal_type(ap, flags));
	else if (s == 'O')
		return (pr_octal_long(va_arg(ap, unsigned long), flags->hash));
	else if (s == 'x')
		return (hex_type(ap, flags, 0));
	else if (s == 'X')
		return (hex_type(ap, flags, 1));
	else if (s == 'u')
		return (unsigned_type(ap, flags));
	else if (s == 'U')
		return (pr_unsigned_long(va_arg(ap, unsigned long)));
	else if (s == 'p')
		return (pr_addr((long)va_arg(ap, void *)));
	else
	{
		str = ft_strnew(sizeof(char)*2);
		str[0] = s;
		str[1] = '\0';
		return (str);
	}
}

char	*make_string(t_flags *flags, char s, va_list ap)
{

	if (s == '%')
		return (pr_char('%'));
	else if (s == 'd' || s == 'i')
		return (dec_type(ap, flags));
	else if (s == 'c')
//		return (pr_char(va_arg(ap, char)));
//	else if (s == 'C')
		return (pr_char_locale(va_arg(ap, char)));
	else if (s == 's')
		return (pr_string(va_arg(ap, char *)));
//	else if (s == 'S')
//		return ();
	else if (s == 'D')
		return (pr_dec_long(va_arg(ap, long), flags->plus));
	else
		return (other_types(flags,s, ap));
}

int		process(va_list ap, char *format, char **result)
{
	char	*save;
	char	*str;
	char	*form;
	t_flags	*flags;

	flags = init_flags();
	save = ft_strdup(*result);
	free(*result);
	form = width_format(&flags, format + 1);
	if ((str = make_string(flags, *(form), ap)) != NULL)
		manage_format(flags, &str);
	*result = ft_strjoin(save, str);
	return (ft_strlen(format) - ft_strlen(form));
}

int		ft_printf(char *format, ...)
{
	int		i;
	char	*c;
	char	*save;
	char	*result;
	va_list ap;

	va_start(ap, format);
	result = ft_strnew(ft_strlen(format));
	i = ft_writetil(&result, format, '%');
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += process(ap, format + i, &result) + 1;
		else
		{
			save = ft_strdup(result);
			free(result);
			c = &format[i];
			result = ft_strjoin(save, c);
			i += ft_strlen(c);
		}
	}
	va_end(ap);
	ft_putstr(result);
	return ((int)ft_strlen(result));
}
