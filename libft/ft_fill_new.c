/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:38:35 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/07/24 15:39:21 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_fill_new(int size, char c)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strnew(size + 1);
	while (i < size)
		s[i++] = c;
	s[i] = '\0';
	return (s);
}
