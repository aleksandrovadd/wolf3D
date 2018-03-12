/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:39:54 by daleksan          #+#    #+#             */
/*   Updated: 2017/02/16 17:26:36 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (s1 && s2)
	{
		str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (*str1 || *str2)
		{
			if (*str1)
				str[i] = *str1++;
			else
				str[i] = *str2++;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}
