/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:54:16 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/04 13:55:08 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modify_x(t_plist *spec, char *str)
{
	int len;

	len = ft_strlen(str);
	if (spec->hesh > 0)
		spec->hesh += 1;
	if (spec->zero == 1 && len > spec->precision && spec->precision != 0)
		spec->zero = 0;
	if (spec->precision < len)
		spec->precision = len;
	if (spec->width < len + spec->hesh)
		spec->width = spec->precision + spec->hesh;
}

void	ft_width_x_2(t_plist *spec, int *len, char *str, char b)
{
	int ln;

	ln = ft_strlen(str);
	if (spec->minus == 1 && spec->width > 0)
	{
		if (spec->hesh > 1)
		{
			*len += ft_pchar(1, '0');
			*len += ft_pchar(1, b);
		}
		*len += ft_pchar(spec->precision - ln, '0');
		*len += ft_pstr(str, 0);
		if (spec->width > spec->precision)
			*len += ft_pchar(spec->width - spec->precision - spec->hesh, ' ');
	}
	else
	{
		*len += ft_pstr(str, 0);
	}
}

void	ft_width_x(t_plist *spec, int *len, char *str, char b)
{
	int ln;

	ln = ft_strlen(str);
	if (spec->minus == 0 && spec->width > 0)
	{
		if (spec->width > spec->precision && spec->zero != 1)
			*len += ft_pchar(spec->width - spec->precision - spec->hesh, ' ');
		if (spec->hesh > 1 && spec->precision == ln && str[0] != '0')
		{
			*len += ft_pchar(1, '0');
			*len += ft_pchar(1, b);
		}
		if (spec->width > spec->precision && spec->zero == 1)
			*len += ft_pchar(spec->width - spec->precision - spec->hesh, '0');
		if (spec->hesh > 1 && spec->precision > ln && str[0] != '0')
		{
			*len += ft_pchar(1, '0');
			*len += ft_pchar(1, b);
		}
		*len += ft_pchar(spec->precision - ln, '0');
		*len += ft_pstr(str, 0);
	}
	else
		ft_width_x_2(spec, len, str, b);
}

void	ft_for_x(t_plist *spec, va_list ap, int *len)
{
	size_t	x;
	char	*tmp;
	char	*str;
	char	b;
	int		m;

	m = 0;
	b = 'x';
	x = 0;
	x = unsigned_length(spec, x, ap);
	tmp = ft_itoa_base(x, 16, m);
	str = tmp;
	if (spec->dot == 1 && x == 0 && spec->precision == 0)
		*len += ft_pchar(spec->width, ' ');
	else
	{
		ft_modify_x(spec, tmp);
		ft_width_x(spec, len, str, b);
	}
	free(tmp);
}

void	ft_for_x_big(t_plist *spec, va_list ap, int *len)
{
	size_t	x;
	char	*tmp;
	char	*str;
	char	b;
	int		m;

	m = 1;
	b = 'X';
	x = 0;
	x = unsigned_length(spec, x, ap);
	tmp = ft_itoa_base(x, 16, m);
	str = tmp;
	if (spec->dot == 1 && x == 0 && spec->precision == 0)
		*len += ft_pchar(spec->width, ' ');
	else
	{
		ft_modify_x(spec, tmp);
		ft_width_x(spec, len, str, b);
	}
	free(tmp);
}
