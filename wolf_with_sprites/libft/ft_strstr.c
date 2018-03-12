/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:16:34 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/05 19:10:42 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (*big != '\0')
	{
		if (*big == little[i])
		{
			while (big[i] == little[i])
			{
				if (little[i + 1] == '\0')
					return ((char *)big);
				++i;
			}
			i = 0;
		}
		++big;
	}
	return (NULL);
}
