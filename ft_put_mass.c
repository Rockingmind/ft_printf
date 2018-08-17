//
// Created by Tania PYROGOVSKA on 8/16/18.
//

#include "ft_printf.h"

void	ft_put_mass(char **mass, int *str_size, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < str_size[i])
		{
			write(1, mass[j], 1);
			j++;
		}
		i++;
	}
}