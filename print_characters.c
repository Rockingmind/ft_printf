/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 18:02:56 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/25 18:03:01 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*init_null_str(t_flags *flags)
{
	char *res;

	res = ft_strdup("(null)");
	flags->cur = 6;
	return (res);
}

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
	char *str;

	if (s == NULL)
		str = init_null_str(flags);
	else
	{
		str = ft_strdup(s);
		flags->cur = ft_strlen(s);
	}
	return (str);
}

char	*put_char_loc(wchar_t ch, t_flags *flags)
{
	int				size;
	unsigned int	c;

	size = bit_count(ch);
	c = (unsigned int)ch;
	if (size <= 7 || MB_CUR_MAX < 2)
		return (mask1(c, flags));
	else if (size <= 11 || MB_CUR_MAX < 3)
		return (mask2(c, flags));
	else if (size <= 16 || MB_CUR_MAX < 4)
		return (mask3(c, flags));
	else
		return (mask4(c, flags, 4034953344));
}

char	*put_str_loc(wchar_t *s, t_flags *flags)
{
	int		i;
	int		size;
	char	*res;
	char	*str;

	size = 0;
	i = 0;
	res = ft_strnew(1);
	if (s == NULL)
		res = init_null_str(flags);
	else
	{
		while (s[i])
		{
			str = ft_strdup(res);
			res = ft_stradd(str, put_char_loc(s[i++], flags), size, flags->cur);
			size += flags->cur;
		}
		flags->cur = size;
	}
	return (res);
}
