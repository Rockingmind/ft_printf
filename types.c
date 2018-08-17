//
// Created by Tania PYROGOVSKA on 8/14/18.
//

#include "ft_printf.h"

char	*dec_type(va_list ap, t_flags *flags, int caps)
{
	if (flags->ref == H)
		return (put_nbr_base(va_arg(ap, short int), 10, flags));
	else if (flags->ref == HH)
		return (put_nbr_base(va_arg(ap, signed int), 10, flags));
	else if (flags->ref == L)
		return (put_nbr_base(va_arg(ap, long int), 10, flags));
	else if (flags->ref == LL)
		return (put_nbr_base(va_arg(ap, long long int), 10, flags));
	else if (flags->ref == Z)
		return (put_nbr_base(va_arg(ap, size_t), 10, flags));
	else if (flags->ref == J)
		return (put_nbr_base(va_arg(ap, intmax_t), 10, flags));
	else if (flags->ref == NONE && caps == 1)
		return (put_nbr_base(va_arg(ap, long), 10, flags));
	else if (flags->ref == NONE && caps == 0)
		return (put_nbr_base(va_arg(ap, int), 10, flags));
}

char	*octal_type(va_list ap, t_flags *flags, int caps)
{
	char *s;

	if (flags->ref == H)
		s = put_nbr_base(va_arg(ap, unsigned short int), 8, flags);
	else if (flags->ref == HH)
		s = put_nbr_base(va_arg(ap, unsigned char), 8, flags);
	else if (flags->ref == L)
		s = put_nbr_base(va_arg(ap, unsigned long int), 8, flags);
	else if (flags->ref == LL)
		s = put_unsigned_nbr(va_arg(ap, unsigned long long int), 8, flags);
	else if (flags->ref == Z)
		s = put_unsigned_nbr(va_arg(ap, size_t), 8, flags);
	else if (flags->ref == J)
		s = put_unsigned_nbr(va_arg(ap, uintmax_t), 8, flags);
	else if (flags->ref == NONE && caps == 0)
		s = put_nbr_base(va_arg(ap, unsigned int), 8, flags);
	else
		s = ft_strjoin("0", put_nbr_base(va_arg(ap, unsigned long), 8, flags));
	if (flags->hash == 1)
		hash(&s, 0);
	return (s);
}

char	*unsigned_type(va_list ap, t_flags *flags, int caps)
{
	if (flags->ref == H)
		return (put_nbr_base(va_arg(ap, unsigned short int), 10, flags));
	else if (flags->ref == HH)
		return (put_nbr_base(va_arg(ap, unsigned char), 10, flags));
	else if (flags->ref == L)
		return (put_nbr_base(va_arg(ap, unsigned long int), 10, flags));
	else if (flags->ref == LL)
		return (put_unsigned_nbr(va_arg(ap, unsigned long long int), 10, flags));
	else if (flags->ref == Z)
		return (put_unsigned_nbr(va_arg(ap, size_t), 10, flags));
	else if (flags->ref == J)
		return (put_unsigned_nbr(va_arg(ap, uintmax_t), 10, flags));
	else if (flags->ref == NONE && caps == 0)
		return (put_nbr_base(va_arg(ap, unsigned int), 10, flags));
	else if (flags->ref == NONE && caps == 1)
		return (put_nbr_base(va_arg(ap, unsigned long), 10, flags));
}

char	*hex_type(va_list ap, t_flags *flags, int p)
{
	char *s;

	if (flags->ref == H)
		s = put_nbr_base(va_arg(ap, unsigned short int), 16, flags);
	else if (flags->ref == HH)
		s = put_nbr_base(va_arg(ap, unsigned char), 16, flags);
	else if (flags->ref == L)
		s = put_nbr_base(va_arg(ap, unsigned long int), 16, flags);
	else if (flags->ref == LL)
		s = put_unsigned_nbr(va_arg(ap, unsigned long long int), 16, flags);
	else if (flags->ref == Z)
		s = put_unsigned_nbr(va_arg(ap, size_t), 16, flags);
	else if (flags->ref == J)
		s = put_unsigned_nbr(va_arg(ap, uintmax_t), 16, flags);
	else if (flags->ref == NONE && p == 0)
		s = put_nbr_base(va_arg(ap, unsigned int), 16, flags);
	else
		s = put_nbr_base((long)va_arg(ap, void *), 16, flags);
	if (flags->hash == 1)
		hash(&s, 1);
	return (s);
}