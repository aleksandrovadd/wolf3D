/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:45:05 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/10 18:07:15 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modify_p(t_plist *spec, char *str)
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

void	ft_width_p_2(t_plist *spec, int *len, char *str, char b)
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
		*len += ft_pstr(str, 0);
}

void	ft_width_p(t_plist *spec, int *len, char *str, char b)
{
	int ln;

	ln = ft_strlen(str);
	if (spec->minus == 0 && spec->width > 0)
	{
		if (spec->width > spec->precision && spec->zero != 1)
			*len += ft_pchar(spec->width - spec->precision - spec->hesh, ' ');
		if (spec->hesh > 1 && spec->precision == ln)
		{
			*len += ft_pchar(1, '0');
			*len += ft_pchar(1, b);
		}
		if (spec->width > spec->precision && spec->zero == 1)
			*len += ft_pchar(spec->width - spec->precision - spec->hesh, '0');
		if (spec->hesh > 1 && spec->precision > ln)
		{
			*len += ft_pchar(1, '0');
			*len += ft_pchar(1, b);
		}
		*len += ft_pchar(spec->precision - ln, '0');
		*len += ft_pstr(str, 0);
	}
	else
		ft_width_p_2(spec, len, str, b);
}

void	ft_p_null(t_plist *spec, char b, int *len)
{
	if (spec->minus == 0 && spec->width > 0)
	{
		if (spec->width > spec->precision && spec->zero != 1)
			*len += ft_pchar(spec->width - 2, ' ');
		if (spec->width > spec->precision && spec->zero == 1)
			*len += ft_pchar(spec->width - 2, '0');
		*len += ft_pchar(1, '0');
		*len += ft_pchar(1, b);
	}
	else if (spec->minus == 1 && spec->width > 0)
	{
		*len += ft_pchar(1, '0');
		*len += ft_pchar(1, b);
		if (spec->width > spec->precision && spec->zero != 1)
			*len += ft_pchar(spec->width - 2, ' ');
	}
	else
	{
		*len += ft_pchar(1, '0');
		*len += ft_pchar(1, b);
	}
}

void	ft_for_p(t_plist *spec, va_list ap, int *len)
{
	uintmax_t	p;
	char		*tmp;
	char		*str;
	char		b;
	int			m;

	m = 0;
	b = 'x';
	p = 0;
	spec->hesh = 1;
	p = (uintmax_t)va_arg(ap, void*);
	tmp = ft_itoa_base(p, 16, m);
	str = tmp;
	if (spec->dot == 1 && p == 0 && spec->precision == 0)
		ft_p_null(spec, b, len);
	else
	{
		ft_modify_p(spec, tmp);
		ft_width_p(spec, len, str, b);
	}
	free(tmp);
}
