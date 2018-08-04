//
// Created by Tania PYROGOVSKA on 8/2/18.
//

#include "ft_printf.h"

void 	right_align(t_flags *flags, char **str)
{
	char *save;
	int add;

	save = ft_strdup(*str);
	free(*str);
	add = flags->min_width - ft_strlen(*str);
	*str = ft_strjoin(ft_fill_new(add, ' '), save);
}