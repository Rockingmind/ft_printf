//
// Created by Tania PYROGOVSKA on 8/4/18.
//

#include "ft_printf.h"

char	*pr_octal_long(unsigned long num, int hash) {
	int size;
	char *s;
	int i;

	i = 0;
	size = count(num, 8);
	if (hash == 1)
		size++;
	s = ft_strnew(size + 1);
	while (size--) {
		s[i] = (int) (num / ft_pow(8, size)) + '0';
		num %= ft_pow(8, size);
		i++;
	}
	s[i] = '\0';
	return (s);
}