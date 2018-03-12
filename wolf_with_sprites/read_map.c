/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:46:42 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/20 18:47:34 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		free_split(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void		parse_map(t_wolf *w, char *line, int y)
{
	int		x;
	char	**str;

	str = ft_strsplit(line, ',');
	x = 0;
	while (x < MAP_WIDTH)
	{
		w->world_map[y][x] = ft_atoi(str[x]);
		x++;
	}
	free_split(str);
}

int			read_map(t_wolf *w)
{
	char	*line;
	int		y;
	int		fd;

	fd = open("map", O_RDONLY);
	y = 0;
	while ((line = get_next_line_fd(fd)))
	{
		parse_map(w, line, y);
		free(line);
		y++;
	}
	close(fd);
	return (0);
}
