/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:35:40 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/20 18:36:11 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_mouse_hook(void)
{
	exit(77);
}

void	change_angle_right(t_wolf *w)
{
	w->old_dir_x = w->dir_x;
	w->dir_x = w->dir_x * cos(-ANGLE) - w->dir_y * sin(-ANGLE);
	w->dir_y = w->old_dir_x * sin(-ANGLE) + w->dir_y * cos(-ANGLE);
	w->old_plane_x = w->plane_x;
	w->plane_x = w->plane_x * cos(-ANGLE) - w->plane_y * sin(-ANGLE);
	w->plane_y = w->old_plane_x * sin(-ANGLE) + w->plane_y * cos(-ANGLE);
}

void	change_angle_left(t_wolf *w)
{
	w->old_dir_x = w->dir_x;
	w->dir_x = w->dir_x * cos(ANGLE) - w->dir_y * sin(ANGLE);
	w->dir_y = w->old_dir_x * sin(ANGLE) + w->dir_y * cos(ANGLE);
	w->old_plane_x = w->plane_x;
	w->plane_x = w->plane_x * cos(ANGLE) - w->plane_y * sin(ANGLE);
	w->plane_y = w->old_plane_x * sin(ANGLE) + w->plane_y * cos(ANGLE);
}

int		key_hook(int key, t_wolf *w)
{
	(key == 53) ? exit(0) : 0;
	if (key == UP_KEY)
	{
		if (w->world_map[(int)(w->pos_x + w->dir_x)][(int)w->pos_y] == 0)
			w->pos_x += w->dir_x;
		if (w->world_map[(int)w->pos_x][(int)(w->pos_y + w->dir_y)] == 0)
			w->pos_y += w->dir_y;
	}
	if (key == D_KEY)
	{
		if (w->world_map[(int)(w->pos_x - w->dir_x)][(int)w->pos_y] == 0)
			w->pos_x -= w->dir_x;
		if (w->world_map[(int)w->pos_x][(int)(w->pos_y - w->dir_y)] == 0)
			w->pos_y -= w->dir_y;
	}
	if (key == R_KEY)
		change_angle_right(w);
	if (key == L_KEY)
		change_angle_left(w);
	return (0);
}

int		funct(t_wolf *w)
{
	redraw_wolf(w);
	return (0);
}
