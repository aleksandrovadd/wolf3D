/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:32:19 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/04 13:33:57 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;
	t_plist	*spec;
	int		count;

	count = 0;
	i = -1;
	spec = (t_plist *)malloc(sizeof(t_plist));
	va_start(ap, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%' &&
			(parse_specif((char *)format, &i, spec, ap)))
		{
			if (spec->type == 'n')
				*(va_arg(ap, uintmax_t *)) = count;
			else
				type_def(spec, ap, &count);
		}
		else if (++count)
			write(1, &format[i], 1);
	}
	va_end(ap);
	free(spec);
	return (count);
}
