/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:12:07 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/24 20:21:05 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	i = 0;
	while (src[i] != '\0' && (i < n))
	{
		dst[i] = src[i];
		i++;
	}
	if (len < n)
	{
		while (i < n)
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (dst);
}
