/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:37:54 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/29 00:26:43 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_modify_d(t_plist *spec, char *str)
{
	int len;

	if (str[0] == '-' || spec->plus == 1 || spec->space == 1)
	{
		if (spec->space == 1 && spec->plus == 0)
			spec->decim = ' ';
		if (str[0] == '-')
		{
			spec->decim = '-';
			str += 1;
		}
		else if (spec->plus == 1)
			spec->decim = '+';
		spec->plus = 1;
	}
	len = ft_strlen(str);
	if (spec->zero == 1 && (spec->minus == 1 || spec->dot == 1))
		spec->zero = 0;
	if (spec->width < len + spec->plus)
		spec->width = len + spec->plus;
	if (spec->width < spec->precision)
		spec->width = spec->precision;
	if (spec->precision < len && spec->width > spec->precision)
		spec->precision = len;
}

void		ft_width_d_2(int ln, t_plist *spec, int *len, char *str)
{
	if (spec->minus == 1 && spec->width > 0)
	{
		if (spec->plus > 0)
			*len += ft_pchar(1, spec->decim);
		if (spec->precision > ln)
			*len += ft_pchar(spec->precision - ln, '0');
		else if (spec->precision < ln)
			*len += ft_pchar(spec->width - ln, '0');
		else if (spec->zero == 1 && spec->precision >= ln)
			*len += ft_pchar(spec->width - spec->precision, '0');
		*len += ft_pstr(str, 0);
		if (spec->width > spec->precision)
			*len += ft_pchar(spec->width - spec->precision - spec->plus, ' ');
	}
	else
	{
		if (spec->decim != '0')
			*len += ft_pchar(1, spec->decim);
		*len += ft_pstr(str, spec->precision);
	}
}

void		ft_width_d(t_plist *spec, int *len, char *str)
{
	int		ln;

	if (str[0] == '-')
		str++;
	ln = ft_strlen(str);
	if (spec->minus == 0 && spec->width > 0)
	{
		if (spec->zero == 0 && spec->width > spec->precision)
			*len += ft_pchar(spec->width - spec->precision - spec->plus, ' ');
		if (spec->plus > 0)
			*len += ft_pchar(1, spec->decim);
		if (spec->zero == 1 && spec->precision >= ln)
			*len += ft_pchar(spec->width - spec->precision - spec->plus, '0');
		*len += ft_pchar(spec->precision - ln, '0');
		*len += ft_pstr(str, 0);
	}
	else
		ft_width_d_2(ln, spec, len, str);
}

void		ft_for_d(t_plist *spec, va_list ap, int *len)
{
	intmax_t	d;
	char		*tmp;
	char		*str;

	d = 0;
	d = signed_length(spec, d, ap);
	tmp = ft_itoa(d);
	str = tmp;
	if (tmp[0] == '-')
		str = tmp + 1;
	if (spec->dot == 1 && d == 0 && spec->precision == 0)
		*len += ft_pchar(spec->width, ' ');
	else
	{
		ft_modify_d(spec, tmp);
		ft_width_d(spec, len, str);
	}
	free(tmp);
}
