/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specif_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:12:25 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/04 15:12:30 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags_check(char *str, int *i, t_plist *spec)
{
	while (str[*i] == '-' || str[*i] == '+' || str[*i] == ' '
		|| str[*i] == '#' || str[*i] == '0')
	{
		if (str[*i] == '-')
			spec->minus = 1;
		if (str[*i] == '+')
			spec->plus = 1;
		if (str[*i] == ' ')
			spec->space = 1;
		if (str[*i] == '#')
			spec->hesh = 1;
		if (str[*i] == '0')
			spec->zero = 1;
		(*i)++;
	}
	return (*i);
}

int	width_check(char *str, int *i, t_plist *spec, va_list ap)
{
	if (str[*i] == '*')
	{
		spec->width = va_arg(ap, int);
		if (spec->width < 0)
		{
			spec->width *= -1;
			spec->minus = 1;
		}
		(*i)++;
	}
	else if (ft_isdigit(str[*i]))
	{
		if (spec->width != 0)
			spec->width = 0;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			spec->width = ((spec->width * 10) + (str[*i] - '0'));
			(*i)++;
		}
	}
	return (*i);
}

int	precis_check(char *str, int *i, t_plist *spec, va_list ap)
{
	if (str[*i] == '.')
	{
		(*i)++;
		if (str[*i] == '*')
		{
			spec->precision = va_arg(ap, int);
			if (spec->precision < 0)
			{
				spec->precision = 0;
				spec->dot = 0;
			}
			(*i)++;
		}
		else if (ft_isdigit(str[*i]))
		{
			if (spec->precision != 0)
				spec->precision = 0;
			while (str[*i] >= '0' && str[*i] <= '9')
			{
				spec->precision = ((spec->precision * 10) + (str[*i] - '0'));
				(*i)++;
			}
		}
	}
	return (*i);
}
