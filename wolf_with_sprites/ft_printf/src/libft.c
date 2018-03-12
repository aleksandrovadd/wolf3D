/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:06:59 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/04 14:10:39 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ia_2(uintmax_t value, unsigned int base, char *str, int *i)
{
	char			*up;

	up = "0123456789ABCDEF";
	if (value >= base)
		ia_2(value / base, base, str, i);
	str[(*i)++] = up[(value % base)];
}

void				ia_b(uintmax_t value, unsigned int base, char *str, int *i)
{
	char			*low;

	low = "0123456789abcdef";
	if (value >= base)
		ia_b(value / base, base, str, i);
	str[(*i)++] = low[(value % base)];
}

char				*ft_itoa_base(uintmax_t value, unsigned int base, int m)
{
	int				i;
	char			*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (0);
	m > 0 ? ia_2(value, base, str, &i) : ia_b(value, base, str, &i);
	str[i] = '\0';
	return (str);
}
