/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 21:31:47 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/21 22:01:58 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*res;

	if (lst && f)
	{
		while (lst)
		{
			res = lst->next;
			f(lst);
			lst = res;
		}
		lst = NULL;
	}
}
