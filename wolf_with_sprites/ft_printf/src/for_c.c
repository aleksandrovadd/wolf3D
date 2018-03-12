/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:36:15 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/10 17:00:43 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_charlen_big(wchar_t c)
{
	int	b;

	b = 0;
	if (c <= 0x7F)
		b++;
	else if (c <= 0x7FF)
		b += 2;
	else if (c <= 0xFFFF)
		b += 3;
	else if (c <= 0x10999)
		b += 4;
	else
		return (0);
	return (b);
}

char	*ft_parce_c_big(wchar_t c, char *z)
{
	int		j;

	j = 0;
	if (c <= 0x7F)
		z[j++] = c;
	else if (c <= 0x7FF)
	{
		z[j++] = ((c >> 6) | 0xC0);
		z[j++] = ((c & 63) | 0x80);
	}
	else if (c <= 0xFFFF)
	{
		z[j++] = ((c >> 12) | 0xE0);
		z[j++] = ((c >> 6 & 63) | 0x80);
		z[j++] = ((c & 63) | 0x80);
	}
	else if (c <= 0x10999)
	{
		z[j++] = ((c >> 18) | 0xF0);
		z[j++] = ((c >> 12 & 63) | 0x80);
		z[j++] = ((c >> 6 & 63) | 0x80);
		z[j++] = ((c & 63) | 0x80);
	}
	z[j] = '\0';
	return (z);
}

void	ft_for_c_big(t_plist *spec, va_list ap, int *len)
{
	wchar_t	c;
	char	*s;
	int		ln;

	c = va_arg(ap, wchar_t);
	if (c == 0)
		*len += 1;
	ln = ft_charlen_big(c);
	s = (char *)malloc(ln + 1);
	ft_parce_c_big(c, s);
	if (spec->width > 0 && spec->minus == 0)
	{
		if (spec->zero == 0)
			*len += ft_pchar(spec->width - ln, ' ');
		else
			*len += ft_pchar(spec->width - ln, '0');
		*len += ft_pstr(s, 0);
	}
	else if (spec->width > 0 && spec->minus == 1)
	{
		*len += ft_pstr(s, 0);
		*len += ft_pchar(spec->width - ln, ' ');
	}
	else
		*len += ft_pstr(s, 0);
}

void	ft_for_c(t_plist *spec, va_list ap, int *len)
{
	char	c;

	if (spec->character == ' ')
		c = (char)va_arg(ap, int);
	else
		c = spec->character;
	if (spec->length == 3 && spec->type == 'c')
		ft_for_c_big(spec, ap, len);
	if (spec->width > 0 && spec->minus == 0)
	{
		if (spec->zero == 0)
			*len += ft_pchar(spec->width - 1, ' ');
		else
			*len += ft_pchar(spec->width - 1, '0');
		*len += ft_pchar(1, c);
	}
	else if (spec->width > 0 && spec->minus == 1)
	{
		*len += ft_pchar(1, c);
		*len += ft_pchar(spec->width - 1, ' ');
	}
	else
		*len += ft_pchar(1, c);
}
