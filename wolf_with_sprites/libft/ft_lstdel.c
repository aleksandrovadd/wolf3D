/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:37:30 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/21 21:41:07 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*res;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		res = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = res;
	}
	*alst = NULL;
}
