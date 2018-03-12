/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:34:55 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/26 18:25:09 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*o;
	size_t			i;

	src = (unsigned char *)s1;
	o = (unsigned char *)s2;
	i = 0;
	while (n > i)
	{
		if (src[i] != o[i])
			return (src[i] - o[i]);
		if (src[i] == '\0' || o[i] == '\0')
			return (src[i] - o[i]);
		i++;
	}
	return (0);
}
