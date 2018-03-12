/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:31:29 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/10 18:08:47 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	length_check(char *str, int *i, t_plist *spec)
{
	if (str[*i] == 'h' && str[*i + 1] == 'h')
	{
		spec->length = (spec->length <= 1) ? 1 : spec->length;
		*i += 2;
	}
	if (str[*i] == 'h' && (spec->length = (spec->length <= 2)
		? 2 : spec->length))
		(*i)++;
	if (str[*i] == 'l' && str[*i + 1] == 'l')
	{
		spec->length = (spec->length <= 4) ? 4 : spec->length;
		*i += 2;
	}
	if (str[*i] == 'l' && (spec->length = (spec->length <= 3)
		? 3 : spec->length))
		(*i)++;
	if (str[*i] == 'j' && (spec->length = (spec->length <= 5)
		? 5 : spec->length))
		(*i)++;
	if (str[*i] == 'z' && (spec->length = 6))
		(*i)++;
	return (spec->length);
}

int	type_check(char *str, int *i, t_plist *spec)
{
	if ((str[*i] == 'd' || str[*i] == 'D' || str[*i] == 'i' || str[*i] == 'o'
		|| str[*i] == 'O' || str[*i] == 'X' || str[*i] == 'x' || str[*i] == 'u'
		|| str[*i] == 'U' || str[*i] == 'c' || str[*i] == 'C' || str[*i] == 's'
		|| str[*i] == 'p' || str[*i] == 'S' || str[*i] == 'n')
		&& (spec->type = str[*i]))
		(*i)++;
	else
		return (0);
	return (*i);
}

int	parse_specif_2(char *format, int *i, t_plist *spec, va_list ap)
{
	int m;

	m = *i;
	(*i)++;
	while (m < (*i))
	{
		m = *i;
		flags_check(format, i, spec);
		width_check(format, i, spec, ap);
		if (format[*i] == '.' && ((format[*i + 1] >= '0' && format[*i + 1]
			<= '9') || format[*i + 1] == '*') && (spec->dot = 1))
			*i = precis_check(format, i, spec, ap);
		else if (format[*i] == '.' && (spec->dot = 1) && ((!(format[*i + 1]
			>= '0' && format[*i + 1] <= '9') || format[*i + 1] != '*')))
		{
			spec->precision = 0;
			(*i)++;
		}
		if (format[*i] == '%' && (spec->percent = '%') && ((*i)++))
			break ;
		spec->length = length_check(format, i, spec);
	}
	return (*i);
}

int	parse_specif(char *format, int *i, t_plist *spec, va_list ap)
{
	int k;

	spec_init(spec);
	parse_specif_2(format, i, spec, ap);
	if (spec->percent != '%' && (k = type_check(format, i, spec)))
		*i = k;
	else if (ft_isprint(format[*i]) && spec->percent != '%')
	{
		spec->character = format[*i];
		(*i)++;
	}
	return ((*i)--);
}
