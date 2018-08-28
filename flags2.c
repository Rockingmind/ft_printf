/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:53:06 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/25 17:53:08 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cut(char **s, t_flags *flags)
{
	char	*save;
	int		i;

	i = 0;
	save = ft_strdup(*s);
	free(*s);
	*s = ft_strnew(flags->precision);
	while (i < flags->precision)
	{
		*((*s) + i) = *(save + i);
		i++;
	}
	flags->cur = flags->precision;
//	free(save);
}

int		is_zero(char *str)
{
	while (*str != '\0')
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

void	hash_hex(char **s, int hash, t_flags *flags)
{
	char *save;

	save = ft_strdup(*s);
	if (!is_zero(*s))
	{
//		free(*s);
		flags->cur += 2;
		if (hash == 1)
			*s = ft_stradd("0x", save, 2, flags->cur);
		else
			*s = ft_stradd("0X", save, 2, flags->cur);
	}
	else if (flags->spec == p)
	{
//		free(*s);
		flags->cur += 2;
		*s = ft_stradd("0x", save, 2, flags->cur);
	}
//	free(save);
}
