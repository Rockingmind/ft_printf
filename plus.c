//
// Created by Tania PYROGOVSKA on 8/13/18.
//

#include "ft_printf.h"

void	plus(char **str)
{
	char *save;

	save = ft_strdup(*str);
	free(*str);
	*str = ft_strjoin("+", save);
}
