/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:08:52 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/05 19:10:39 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (*big != '\0' && len > 0)
	{
		if (*big == little[i])
		{
			while (big[i] == little[i] && i <= len)
			{
				if (little[i + 1] == '\0')
					return ((char *)big);
				++i;
			}
			i = 0;
		}
		++big;
		--len;
	}
	return (NULL);
}
