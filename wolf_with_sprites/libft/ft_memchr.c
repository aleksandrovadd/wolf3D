/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:29:45 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/05 16:05:04 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;

	ch = (unsigned char)c;
	str = (unsigned char *)s;
	if (n)
	{
		while (n > 0)
		{
			if (*str == ch)
				return (str);
			n--;
			str++;
		}
	}
	return (NULL);
}
