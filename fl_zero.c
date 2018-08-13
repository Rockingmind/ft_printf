//
// Created by Tania PYROGOVSKA on 7/24/18.
//

#include "ft_printf.h"

void	fl_zero(t_flags *flags, char **str)
{
	int add;
	char *save;
	char *s;

	if (flags->precision > 0)
		add = flags->precision - ft_strlen(*str);
	else
		add = flags->min_width - ft_strlen(*str);
	if (add > 0) {
		save = ft_strdup(*str);
		free(*str);
		if (*save == '-') {
			if (flags->precision > 0)
				add++;
			s = ft_strjoin("-", ft_fill_new(add, '0'));
			*str = ft_strjoin(s, save + 1);
			free(s);
		} else
			*str = ft_strjoin(ft_fill_new(add, '0'), save);
		free(save);
	}
}