#include <stdio.h>
#include "ft_printf.h"

int main() {
	int i;

	i = ft_printf("sld;ka %c 67", '\0');
	printf(" %d\n");
	i = printf("sld;ka %c 67", '\0');
	printf(" %d\n");
	return 0;
}