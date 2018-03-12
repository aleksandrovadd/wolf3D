/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:08:33 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/09 18:08:54 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reset_buffer(char *b)
{
	int		i;

	i = 0;
	while (i < MAX_LINE + 1)
		b[i++] = '\0';
}

char		*get_next_line_fd(int fd)
{
	char	b[MAX_LINE + 1];
	int		done;
	int		line;

	done = 0;
	line = done;
	reset_buffer(b);
	if ((read(fd, NULL, 0) < 0) && fd > 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	while (done += read(fd, &b[done], 1))
	{
		if ((b[done - 1] == '\n') || done == line)
			return (ft_strdup(b));
		line = done;
	}
	return (NULL);
}
