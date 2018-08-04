#include <stdio.h>
#include "ft_printf.h"
int main() {
	char *s;

	s = ft_strnew(1);
	printf("%p\n", s);
	ft_printf("%p\n", s);
//	printf("kdfhdkf%05d", 10);
//	ft_printf("%D", 1003);
	return 0;
}