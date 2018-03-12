/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 21:43:19 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/27 18:45:08 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*res_frst;

	if (!lst || !f)
		return (0);
	res = f(lst);
	res_frst = res;
	while (lst->next)
	{
		res->next = f(lst->next);
		if (res->next == NULL)
			return (0);
		lst = lst->next;
		res = res->next;
	}
	return (res_frst);
}
