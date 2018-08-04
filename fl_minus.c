//
// Created by Tania PYROGOVSKA on 7/24/18.
//

#include "ft_printf.h"

void	fl_minus(t_flags *flags, char **str)
{
	int		add;
	char	*s;

	s = ft_strdup(*str);
	add = flags->min_width - (int)ft_strlen(*str);
	free(*str);
	*str = ft_strjoin(s, ft_fill_new(add, ' '));
	free(s);
}