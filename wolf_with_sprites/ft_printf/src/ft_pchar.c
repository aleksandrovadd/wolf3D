/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:34:24 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/04 13:35:35 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pstr(char *str, int len)
{
	int j;

	j = 0;
	if (len > 0)
	{
		while (j < len)
		{
			write(1, &str[j], 1);
			j++;
		}
	}
	else
	{
		while (str[j] != '\0')
		{
			write(1, &str[j], 1);
			j++;
		}
	}
	return (j);
}

int	ft_pchar(int i, char c)
{
	int j;

	j = 0;
	while (j < i)
	{
		write(1, &c, 1);
		j++;
	}
	return (j);
}
