/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:47:49 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/20 18:48:20 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		parse_sprites(t_wolf *w, char *line, int y)
{
	int		x;
	char	**str;

	str = ft_strsplit(line, ',');
	x = 0;
	while (x < 3)
	{
		w->spr_map[y][x] = atof(str[x]);
		x++;
	}
	free_split(str);
}

int			read_sprites(t_wolf *w)
{
	char	*line;
	int		y;
	int		fd;

	fd = open("sprites", O_RDONLY);
	y = 0;
	while ((line = get_next_line_fd(fd)))
	{
		parse_sprites(w, line, y);
		free(line);
		y++;
	}
	close(fd);
	return (0);
}
