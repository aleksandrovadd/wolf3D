/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:10:54 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/24 18:16:23 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*src;
	unsigned char	*o;

	src = (unsigned char *)s1;
	o = (unsigned char *)s2;
	if (*src == '\0' && *o == '\0')
		return (0);
	while (*src == *o && *src != '\0' && *o != '\0')
	{
		src++;
		o++;
	}
	return (*src - *o);
}
