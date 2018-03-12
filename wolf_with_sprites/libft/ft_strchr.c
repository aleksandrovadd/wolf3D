/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:39:31 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/21 19:25:24 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*str;

	str = (char *)s;
	ch = (char)c;
	if (*str == ch)
		return (str);
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	return (NULL);
}
