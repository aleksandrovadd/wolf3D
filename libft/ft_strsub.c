/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:41:16 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/13 17:41:58 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	if (s)
	{
		if (!(str = (char *)malloc(len + 1)))
			return (NULL);
		while (len > 0)
		{
			str[i] = s[i + start];
			len--;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}
