//
// Created by Tania PYROGOVSKA on 7/20/18.
//

#include "ft_printf.h"

char	*other_types(t_flags *flags, char s, va_list ap)
{
	if (s == 'o')
		return (pr_octal(va_arg(ap, unsigned int), flags->hash));
//	else if (s == 'O')
//		return ();
	else if (s == 'x')
		return (pr_hex(va_arg(ap, unsigned int), flags->hash));
//	else if (s == 'X')
//		return ();
	else if (s == 'u')
		return (pr_unsigned_int(va_arg(ap, unsigned int)));
//	else if (s == 'U')
//		return ();
	else if (s == 'p')
		return (pr_addr((long)va_arg(ap, void *)));
//	else
//		return (&s);
	return (0);
}

char	*make_string(t_flags *flags, char s, va_list ap) {

	if (s == '%')
		return (pr_char('%'));
	else if (s == 'd' || s == 'i')
		return (pr_dec(va_arg(ap, int), flags->plus));
//	else if (s == 'c')
//		return (pr_char(va_arg(ap, char)));
//	else if (s == 'C')
//		return ();
	else if (s == 's')
		return (pr_string(va_arg(ap, char *)));
//	else if (s == 'S')
//		return ();
	else if (s == 'D')
		return (pr_dec_long(va_arg(ap, long), flags->plus));
	else
		return (other_types(flags,s, ap));
	return (0);
}

int		process(va_list ap, char *format, char **result)
{
	char	*save;
	char	*str;
	char	*flag;
	t_flags	*flags;

	flags = init_flags();
	save = ft_strdup(*result);
	free(*result);
	flag = width_format(&flags, format + 1);
	str = make_string(flags, *(flag ), ap);
	manage_format(flags, &str);
	*result = ft_strjoin(save, str);
	return (ft_strlen(format) - ft_strlen(flag));
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
			i += process(ap, format, &result) + 1;
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
