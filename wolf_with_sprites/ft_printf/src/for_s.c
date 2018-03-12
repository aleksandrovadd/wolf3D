/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:03:31 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/10 18:06:35 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		for_w_char(wchar_t s, char *z, int *b, int d)
{
	int j;

	j = 0;
	if (s <= 0x7F && ((d == 0 || ((*b -= 1) >= 0))))
		z[j++] = s;
	else if (s <= 0x7FF && ((d == 0) || ((*b -= 2) >= 0)))
	{
		z[j++] = ((s >> 6) | 0xC0);
		z[j++] = ((s & 63) | 0x80);
	}
	else if (s <= 0xFFFF && ((d == 0) || ((*b -= 3) >= 0)))
	{
		z[j++] = ((s >> 12) | 0xE0);
		z[j++] = ((s >> 6 & 63) | 0x80);
		z[j++] = ((s & 63) | 0x80);
	}
	else if (s <= 0x10999 && ((d == 0) || ((*b -= 4) >= 0)))
	{
		z[j++] = ((s >> 18) | 0xF0);
		z[j++] = ((s >> 12 & 63) | 0x80);
		z[j++] = ((s >> 6 & 63) | 0x80);
		z[j++] = ((s & 63) | 0x80);
	}
	z[j] = '\0';
	return (j);
}

char	*ft_s_big_parse(t_plist *spec, wchar_t *s, char *z)
{
	int		i;
	int		j;
	int		b;
	int		d;

	i = 0;
	j = 0;
	d = spec->dot;
	b = spec->precision;
	while (s[i] != '\0')
	{
		j += for_w_char(s[i], &z[j], &b, d);
		i++;
	}
	z[j] = '\0';
	return (z);
}

void	ft_for_s_big(t_plist *spec, va_list ap, int *len)
{
	size_t	ln;
	wchar_t	*s;
	char	*z;

	s = va_arg(ap, wchar_t*);
	if (s == NULL)
		z = ft_strdup("(null)");
	else
	{
		ln = ft_strlen_s(s);
		if (!(z = (char*)malloc(sizeof(char) * ln + 1)))
			return ;
		z = ft_s_big_parse(spec, s, z);
	}
	ft_width_s(spec, len, z);
	free(z);
}

void	ft_width_s(t_plist *spec, int *len, char *s)
{
	int ln;

	ln = ft_strlen(s);
	if (spec->precision > ln)
		spec->precision = ln;
	else if ((spec->precision > 0 || (spec->precision == 0
		&& spec->dot == 1)) && ln != 0)
		ln = spec->precision;
	if (spec->width > 0 && spec->minus == 0)
	{
		if (spec->zero == 0)
			*len += ft_pchar(spec->width - ln, ' ');
		else
			*len += ft_pchar(spec->width - ln, '0');
		if (ln != 0)
			*len += ft_pstr(s, spec->precision);
	}
	else if (spec->width > 0 && spec->minus == 1)
	{
		if (ln != 0)
			*len += ft_pstr(s, spec->precision);
		*len += ft_pchar(spec->width - ln, ' ');
	}
	else if (ln != 0)
		*len += ft_pstr(s, spec->precision);
}

void	ft_for_s(t_plist *spec, va_list ap, int *len)
{
	char	*s;

	if (spec->length == 3)
		ft_for_s_big(spec, ap, len);
	else
	{
		s = va_arg(ap, char*);
		if (s == NULL)
			s = "(null)";
		ft_width_s(spec, len, s);
	}
}
