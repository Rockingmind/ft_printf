//
// Created by Tania PYROGOVSKA on 8/8/18.
//

#include "ft_printf.h"

char	*dec_type(va_list ap, t_flags *flags)
{
	if (flags->H == 1)
		return (short_int(va_arg(ap, short int)));
	else if (flags->HH == 1)
		return (char_int(va_arg(ap, signed char)));
	else if (flags->L == 1)
		return (long_int(va_arg(ap, long int)));
	else if (flags->LL == 1)
		return (long_long_int(va_arg(ap, long long int)));
	else if (flags->Z == 1)
		return (sizet_int(va_arg(ap, size_t)));
	else if (flags->J == 1)
		return (intmaxt_int(va_arg(ap, intmax_t)));
}

char	*unsigned_type(va_list ap, t_flags *flags)
{
	if (flags->H == 1)
		return (short_usigned(va_arg(ap, unsigned short int)));
	else if (flags->HH == 1)
		return (char_unsigned(va_arg(ap, unsigned char)));
	else if (flags->L == 1)
		return (long_unsigned(va_arg(ap, unsigned long int)));
	else if (flags->LL == 1)
		return (long_long_unsign(va_arg(ap, unsigned long long int)));
	else if (flags->Z == 1)
		return (sizet_unsign(va_arg(ap, size_t)));
	else if (flags->J == 1)
		return (intmaxt_unsign(va_arg(ap, uintmax_t)));
}

char	*octal_type(va_list ap, t_flags *flags)
{
	if (flags->H == 1)
		return (short_octal(va_arg(ap, unsigned short int)));
	else if (flags->HH == 1)
		return (char_octal(va_arg(ap, unsigned char)));
	else if (flags->L == 1)
		return (long_octal(va_arg(ap, unsigned long int)));
	else if (flags->LL == 1)
		return (long_long_octal(va_arg(ap, unsigned long long int)));
	else if (flags->Z == 1)
		return (sizet_octal(va_arg(ap, size_t)));
	else if (flags->J == 1)
		return (intmaxt_octal(va_arg(ap, uintmax_t)));
}

char	*hex_type(va_list ap, t_flags *flags, int caps)
{
	if (flags->H == 1)
		return (short_hex(va_arg(ap, unsigned short int), 0));
	else if (flags->HH == 1)
		return (char_hex(va_arg(ap, unsigned char), 0));
	else if (flags->L == 1)
		return (long_hex(va_arg(ap, unsigned long int), 0));
	else if (flags->LL == 1)
		return (long_long_hex(va_arg(ap, unsigned long long int), 0));
	else if (flags->Z == 1)
		return (sizet_hex(va_arg(ap, size_t), 0));
	else if (flags->J == 1)
		return (intmaxt_hex(va_arg(ap, uintmax_t), 0));
}

char	*hex_caps_type(va_list ap, t_flags *flags)
{
	if (flags->H == 1)
		return (short_hex(va_arg(ap, unsigned short int), 1));
	else if (flags->HH == 1)
		return (char_hex(va_arg(ap, unsigned char), 1));
	else if (flags->L == 1)
		return (long_hex(va_arg(ap, unsigned long int), 1));
	else if (flags->LL == 1)
		return (long_long_hex(va_arg(ap, unsigned long long int), 1));
	else if (flags->Z == 1)
		return (sizet_hex(va_arg(ap, size_t), 1));
	else if (flags->J == 1)
		return (intmaxt_hex(va_arg(ap, uintmax_t), 1));
}