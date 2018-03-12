/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:29:13 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/21 19:35:08 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned char	ch;

	ch = (unsigned char)c;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (n)
	{
		while (n > 0)
		{
			if (*src1 == ch)
			{
				*dst1 = *src1;
				return (++dst1);
			}
			*dst1++ = *src1++;
			n--;
		}
	}
	return (NULL);
}
