/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:48:17 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/25 17:52:37 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	plus(char **s, t_flags *flags)
{
	char *save;

	free(*s);
	save = ft_strdup(*s);
	if (flags->neg == 0)
		*s = ft_stradd("+", save, 1, flags->cur);
	else
		*s = ft_stradd("-", save, 1, flags->cur);
	flags->cur++;
}

void	zero(char **s, int width, t_flags *flags)
{
	int		size;
	char	*save;

	size = width - flags->cur;
	if (size > 0)
	{
		save = ft_strdup(*s);
		*s = ft_stradd(ft_fill_new(size, '0'), save, size, flags->cur);
		flags->cur += size;
	}
}

void	space(char **s, t_flags *flags)
{
	int		size;
	char	*save;

	size = flags->width - flags->cur;
	if (size > 0)
	{
		save = ft_strdup(*s);
		if (flags->minus == 1)
			*s = ft_stradd(save, ft_fill_new(size, ' '), flags->cur, size);
		else
			*s = ft_stradd(ft_fill_new(size, ' '), save, size, flags->cur);
		flags->cur += size;
	}
}

void	space_before(char **s, t_flags *flags)
{
	char *save;

	if (**s != '-' && **s != '+')
	{
		save = ft_strdup(*s);
		*s = ft_stradd(" ", save, 1, flags->cur);
		flags->cur++;
	}
}

void	hash(char **s, t_flags *flags)
{
	char *save;

	save = ft_strdup(*s);
	flags->cur += 1;
	if (ft_atoi(save) != 0)
	{
		*s = ft_stradd("0", save, 1, flags->cur);
	}
	else
	{
		*s = ft_stradd("0", save, 1, 0);
		flags->cur = 1;
	}
}
