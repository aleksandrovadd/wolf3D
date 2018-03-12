/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:07:02 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/13 20:47:20 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int s, size_t len)
{
	unsigned char	*nb;
	int				i;

	i = 0;
	nb = (unsigned char *)b;
	while (len > 0)
	{
		nb[i] = s;
		len--;
		i++;
	}
	return ((void *)b);
}
