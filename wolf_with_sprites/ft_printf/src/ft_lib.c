/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:29:25 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/04 14:30:17 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen_s(wchar_t *str)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 0x7F)
			b++;
		else if (str[i] <= 0x7FF)
			b += 2;
		else if (str[i] <= 0xFFFF)
			b += 3;
		else if (str[i] <= 0x10999)
			b += 4;
		else
			return (0);
		i++;
	}
	return (b);
}
