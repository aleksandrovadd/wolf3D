/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:12:52 by daleksan          #+#    #+#             */
/*   Updated: 2017/04/04 15:13:24 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_plist	spec_init(t_plist *spec)
{
	spec->minus = 0;
	spec->plus = 0;
	spec->space = 0;
	spec->hesh = 0;
	spec->zero = 0;
	spec->width = 0;
	spec->precision = 0;
	spec->length = 0;
	spec->type = ' ';
	spec->decim = '0';
	spec->percent = ' ';
	spec->dot = 0;
	spec->character = ' ';
	return (*spec);
}
