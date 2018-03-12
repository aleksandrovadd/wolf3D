/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:42:07 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/10 17:03:06 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modify_o(t_plist *spec, char *str)
{
	int len;

	len = ft_strlen(str);
	if (spec->precision < len)
		spec->precision = len;
	if (spec->zero == 1 && spec->precision > len)
		spec->zero = 0;
	if (spec->hesh == 1 && spec->precision > len)
		spec->hesh = 0;
	if (spec->width < len + spec->hesh)
		spec->width = spec->precision + spec->hesh;
}

void	ft_width_o_2(int ln, t_plist *spec, int *len, char *str)
{
	if (spec->minus == 1 && spec->width > 0)
	{
		if (spec->hesh == 1)
			*len += ft_pchar(1, '0');
		*len += ft_pchar(spec->precision - ln, '0');
		*len += ft_pstr(str, 0);
		if (spec->width > spec->precision)
			*len += ft_pchar(spec->width - spec->precision - spec->hesh, ' ');
	}
	else
		*len += ft_pstr(str, 0);
}

void	ft_width_o(t_plist *spec, int *len, char *str)
{
	int ln;

	ln = ft_strlen(str);
	if (spec->minus == 0 && spec->width > 0)
	{
		if (spec->zero == 0 && spec->width > spec->precision)
			*len += ft_pchar(spec->width - spec->precision - spec->hesh, ' ');
		if (spec->hesh == 1 && spec->precision == ln && (str[0] != '0'))
			*len += ft_pchar(1, '0');
		if (spec->width > spec->precision && spec->zero == 1)
			*len += ft_pchar(spec->width - spec->precision - spec->hesh, '0');
		if (spec->hesh == 1 && spec->precision > ln && (str[0] != '0'))
			*len += ft_pchar(1, '0');
		*len += ft_pchar(spec->precision - ln, '0');
		*len += ft_pstr(str, 0);
	}
	else
		ft_width_o_2(ln, spec, len, str);
}

void	ft_for_o(t_plist *spec, va_list ap, int *len)
{
	size_t	o;
	char	*tmp;
	char	*str;
	int		m;

	m = 1;
	o = 0;
	o = unsigned_length(spec, o, ap);
	tmp = ft_itoa_base(o, 8, m);
	str = tmp;
	if (spec->hesh == 0 && spec->dot == 1 && o == 0 && spec->precision == 0)
		*len += ft_pchar(spec->width, ' ');
	else
	{
		ft_modify_o(spec, tmp);
		ft_width_o(spec, len, str);
	}
	free(tmp);
}
