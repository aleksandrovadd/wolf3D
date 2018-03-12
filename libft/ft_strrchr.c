/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:55:51 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/24 16:16:08 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*str;
	int		len;

	str = (char *)s;
	ch = (char)c;
	len = 0;
	while (str[len] != '\0')
		len++;
	if (str[len] == ch)
		return (&str[len]);
	while (len >= 0)
	{
		if (str[len] == ch)
			return (&str[len]);
		len--;
	}
	return (NULL);
}
