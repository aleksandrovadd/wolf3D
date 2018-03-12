/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:35:42 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/09 15:57:10 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			count_num(intmax_t number)
{
	unsigned int	i;
	uintmax_t		a;

	i = 0;
	if (number < 0)
	{
		a = -number;
		i++;
	}
	else
		a = number;
	while (a >= 10)
	{
		i++;
		a = a / 10;
	}
	if (a < 10)
		i++;
	return (i);
}

char				*ft_itoa(intmax_t number)
{
	intmax_t		i;
	char			*str;
	uintmax_t		a;
	int				negat;

	negat = 1;
	i = count_num(number);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	if (number < 0)
	{
		a = -number;
		negat = -1;
	}
	else
		a = number;
	while (i--)
	{
		str[i] = a % 10 + 48;
		a = a / 10;
	}
	if (negat == -1)
		str[0] = '-';
	return (str);
}
