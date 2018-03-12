/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_modify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:13:41 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/04 15:14:31 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modify_d(t_plist *spec, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] == '-')
		len--;
	if (str[0] == '-' || spec->plus == 1 || spec->space == 1 || spec->hesh == 1)
	{
		if (spec->space == 1 && spec->plus == 0)
			spec->decim = ' ';
		if (spec->hesh == 1)
			spec->decim = '0';
		if (str[0] == '-')
			spec->decim = '-';
		else if (spec->plus == 1)
			spec->decim = '+';
		spec->plus = 1;
	}
	if (spec->zero == 1 && len > spec->precision)
		spec->zero = 0;
	if (spec->width < len + spec->plus)
		spec->width = len + spec->plus;
	if (spec->precision < len + spec->plus)
		spec->precision = len + spec->plus;
	else if (spec->precision > len)
		spec->precision += spec->plus;
}
