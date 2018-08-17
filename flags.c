//
// Created by Tania PYROGOVSKA on 8/14/18.
//

#include "ft_printf.h"

void	plus(char **s)
{
	char *save;

	save = ft_strdup(*s);
	free(*s);
	*s = ft_strjoin("+", save);
}

void	zero(char **s, int width)
{
	int size;
	char *save;

	size = width - ft_strlen(*s);
	if (size > 0)
	{
		save = ft_strdup(*s);
		free(*s);
		*s = ft_strjoin(ft_fill_new(size, '0'), save);
	}
}

void	space(char **s, t_flags *flags)
{
	int size;
	char *save;

	size = flags->width - ft_strlen(*s);
	if (size > 0)
	{
		save = ft_strdup(*s);
		free(*s);
		*s = ft_strjoin(ft_fill_new(size, ' '), save);
	}
}

void	hash(char **s, int hash)
{
	char *save;

	save = ft_strdup(*s);
	free(*s);
	if (hash == 0)
		*s = ft_strjoin("0", save);
	else
		*s = ft_strjoin("0x", save);
}

void	minus(char **s, t_flags *flags)
{
	int		size;
	char	*save;

	size = flags->width - ft_strlen(*s);
	if (size > 0)
	{
		save = ft_strdup(*s);
		free(*s);
		*s = ft_strjoin(save, ft_fill_new(size, ' '));
	}
}