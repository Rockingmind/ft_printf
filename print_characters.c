//
// Created by Tania PYROGOVSKA on 8/14/18.
//

#include "ft_printf.h"

char	*put_char(char c, t_flags *flags)
{
	char *s;

	s = ft_strnew(1);
	s[0] = c;
	flags->cur = 1;
	return (s);
}

char	*str_out(char *s, t_flags *flags)
{
	flags->cur = (int)ft_strlen(s);
	return (s);
}

char	*put_char_loc(wchar_t ch, t_flags *flags)
{
	int				size;
	unsigned int	c;

	size = bit_count(ch);
	c = (unsigned int)ch;
	if (size < 7 || MB_CUR_MAX < 2)
		return (mask1(c, flags));
	else if (size < 11 || MB_CUR_MAX < 3)
		return (mask2(c, flags));
	else if (size < 16 || MB_CUR_MAX < 4)
		return (mask3(c, flags));
	else
		return (mask4(c, flags));
}

char	*put_str_loc(wchar_t *s, t_flags *flags)
{
	int i;
	int size;
	char *res;
	char *str;

	size = 0;
	i = 0;
	res = ft_strnew(1);
	while (s[i])
	{
		str = ft_strdup(res);
		free(res);
		res = ft_stradd(str, put_char_loc(*s, flags), size, flags->cur);
		size += flags->cur;
		free(str);
		i++;
	}
	flags->cur = size;
	return (res);
}