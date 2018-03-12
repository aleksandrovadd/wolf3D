/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_def.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:14:45 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/04 15:14:59 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_def(t_plist *spec, va_list ap, int *len)
{
	if (spec->type == 'd' || spec->type == 'i')
		ft_for_d(spec, ap, len);
	else if (spec->type == 'D')
	{
		spec->length = 3;
		ft_for_d(spec, ap, len);
	}
	else if (spec->type == 'o')
		ft_for_o(spec, ap, len);
	else if (spec->type == 'O')
	{
		spec->length = 3;
		ft_for_o(spec, ap, len);
	}
	else if (spec->type == 'u')
		ft_for_u(spec, ap, len);
	else if (spec->type == 'U')
	{
		spec->length = 3;
		ft_for_u(spec, ap, len);
	}
	else
		type_def_2(spec, ap, len);
}

void	type_def_2(t_plist *spec, va_list ap, int *len)
{
	if (spec->type == 'x')
		ft_for_x(spec, ap, len);
	else if (spec->type == 'X')
		ft_for_x_big(spec, ap, len);
	else if (spec->type == 'c' || spec->character != ' ')
		ft_for_c(spec, ap, len);
	else if (spec->type == 'C')
		ft_for_c(spec, ap, len);
	else if (spec->type == 's')
		ft_for_s(spec, ap, len);
	else if (spec->type == 'S')
		ft_for_s_big(spec, ap, len);
	else if (spec->type == 'p')
		ft_for_p(spec, ap, len);
	if (spec->percent == '%')
		ft_for_perc(spec, len);
}

void	ft_for_perc(t_plist *spec, int *len)
{
	if (spec->width > 0 && spec->minus == 0)
	{
		if (spec->zero == 0)
			*len += ft_pchar(spec->width - 1, ' ');
		else
			*len += ft_pchar(spec->width - 1, '0');
		*len += ft_pchar(1, '%');
	}
	else if (spec->width > 0 && spec->minus == 1)
	{
		*len += ft_pchar(1, '%');
		*len += ft_pchar(spec->width - 1, ' ');
	}
	else
		*len += ft_pchar(1, '%');
}
