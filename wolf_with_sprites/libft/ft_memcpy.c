/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:31:20 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/13 20:55:29 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	int				i;

	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (len > 0)
	{
		dst1[i] = src1[i];
		len--;
		i++;
	}
	return ((void *)dst);
}
