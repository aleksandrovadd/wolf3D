/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:03:13 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/04 14:04:12 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	signed_length(t_plist *spec, intmax_t d, va_list ap)
{
	if (spec->length == 2)
		d = (short)va_arg(ap, intmax_t);
	else if (spec->length == 3)
		d = (long)va_arg(ap, intmax_t);
	else if (spec->length == 4)
		d = (long long)va_arg(ap, intmax_t);
	else if (spec->length == 1)
		d = (char)va_arg(ap, intmax_t);
	else if (spec->length == 5)
		d = (intmax_t)va_arg(ap, intmax_t);
	else if (spec->length == 6)
		d = (size_t)va_arg(ap, intmax_t);
	else
		d = (int)va_arg(ap, intmax_t);
	return (d);
}

size_t		unsigned_length(t_plist *spec, size_t o, va_list ap)
{
	if (spec->length == 2)
		o = (unsigned short)va_arg(ap, size_t);
	else if (spec->length == 3)
		o = (unsigned long)va_arg(ap, size_t);
	else if (spec->length == 4)
		o = (unsigned long long)va_arg(ap, size_t);
	else if (spec->length == 1)
		o = (unsigned char)va_arg(ap, size_t);
	else if (spec->length == 5)
		o = (uintmax_t)va_arg(ap, size_t);
	else if (spec->length == 6)
		o = (size_t)va_arg(ap, size_t);
	else
		o = (unsigned int)va_arg(ap, size_t);
	return (o);
}
