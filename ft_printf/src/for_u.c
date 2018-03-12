/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:52:55 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/10 18:08:14 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modify_u(t_plist *spec, char *str)
{
	int len;

	len = ft_strlen(str);
	if (spec->precision < len)
		spec->precision = len;
	if (spec->zero == 1 && spec->precision > len)
		spec->zero = 0;
	if (spec->width < len)
		spec->width = len;
}

void	ft_width_u_2(int ln, t_plist *spec, int *len, char *str)
{
	if (spec->minus == 1 && spec->width > 0)
	{
		if (spec->precision > ln)
			*len += ft_pchar(spec->precision - ln, '0');
		else if (spec->precision < ln)
			*len += ft_pchar(spec->width - ln, '0');
		else if (spec->zero == 1 && spec->precision > ln)
			*len += ft_pchar(spec->width - spec->precision, '0');
		*len += ft_pstr(str, 0);
		if (spec->width > spec->precision)
			*len += ft_pchar(spec->width - spec->precision, ' ');
	}
	else
		*len += ft_pstr(str, spec->precision);
}

void	ft_width_u(t_plist *spec, int *len, char *str)
{
	int ln;

	ln = ft_strlen(str);
	if (spec->minus == 0 && spec->width > 0)
	{
		if (spec->zero == 0 && spec->width > spec->precision)
			*len += ft_pchar(spec->width - spec->precision, ' ');
		if (spec->precision > ln)
			*len += ft_pchar(spec->precision - ln, '0');
		else if (spec->precision < ln)
			*len += ft_pchar(spec->width - ln, '0');
		else if (spec->zero == 1 && spec->precision >= ln)
			*len += ft_pchar(spec->width - spec->precision, '0');
		*len += ft_pstr(str, 0);
	}
	else
		ft_width_u_2(ln, spec, len, str);
}

void	ft_for_u(t_plist *spec, va_list ap, int *len)
{
	size_t	u;
	char	*tmp;
	char	*str;
	int		m;

	u = 0;
	m = 0;
	u = unsigned_length(spec, u, ap);
	tmp = ft_itoa_base(u, 10, m);
	str = tmp;
	if (spec->dot == 1 && u == 0 && spec->precision == 0)
		*len += ft_pchar(spec->width, ' ');
	else
	{
		ft_modify_u(spec, tmp);
		ft_width_u(spec, len, str);
	}
	free(tmp);
}
