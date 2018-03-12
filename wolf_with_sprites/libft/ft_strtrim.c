/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:42:20 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/27 19:34:42 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	separator(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		o;
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen((char *)s);
	i = 0;
	j = 0;
	while (separator(s[len - 1]) == 1)
		len--;
	while (separator(s[i]) == 1)
		i++;
	o = len - i;
	if (o <= 0)
		o = 0;
	str = (char *)malloc(sizeof(char) * o + 1);
	if (!str)
		return (NULL);
	while (o--)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
