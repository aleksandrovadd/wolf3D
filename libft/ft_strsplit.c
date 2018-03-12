/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:58:32 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/27 18:44:34 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_c(char *str, char separ, int i)
{
	while (str[i] != separ && str[i])
		i++;
	return (i);
}

static size_t	count_w(char *str, char separ)
{
	long int	i;
	size_t		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == separ && str[i + 1] != separ) || str[0] != separ)
			j++;
		i++;
	}
	return (j);
}

static char		**arr_parse(char const *s, char c, char **str)
{
	long int	wi;
	long int	chi;
	long int	i;

	i = 0;
	wi = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			chi = 0;
			if (!(str[wi] = (char *)ft_memalloc(count_c((char *)s, c, i) + 1)))
				return (ft_memfree(str, wi));
			while (s[i] != c && s[i])
				str[wi][chi++] = s[i++];
			str[wi++][chi] = '\0';
		}
	}
	str[wi] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;

	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * count_w((char *)s, c) + 1)))
		return (NULL);
	str = arr_parse(s, c, str);
	return (str);
}
