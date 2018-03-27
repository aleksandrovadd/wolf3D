/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:31:54 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/20 18:34:14 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			draw_ceiling(t_wolf *w)
{
	long int	i;

	w->y = 0;
	while (w->y < w->draw_start)
	{
		w->color = 0x3e3f42;
		i = w->y * F_SW + w->x * 4;
		w->pxl[i] = w->color;
		w->pxl[i + 1] = w->color >> 8;
		w->pxl[i + 2] = w->color >> 16;
		w->y++;
	}
}

void			draw_floor(t_wolf *w)
{
	long int	i;

	w->y = w->draw_end;
	while (w->y < SCR_H)
	{
		w->txt2 = w->floor;
		floor_manage(w);
		w->current_dist = SCR_H / (2.0 * w->y - SCR_H);
		w->weight = (w->current_dist - w->dist_player) /
		(w->dist_wall - w->dist_player);
		w->current_floor_x = w->weight * w->floor_x_wall +
		(1.0 - w->weight) * w->pos_x;
		w->current_floor_y = w->weight * w->floor_y_wall +
		(1.0 - w->weight) * w->pos_y;
		w->floor_tex_x = (int)(w->current_floor_x * w->tex_width)
		% w->tex_width;
		w->floor_tex_y = (int)(w->current_floor_y * w->tex_height)
		% w->tex_height;
		grab_color_floor(w);
		i = w->y * F_SW + w->x * 4;
		w->pxl[i] = w->b2;
		w->pxl[i + 1] = w->g2;
		w->pxl[i + 2] = w->r2;
		w->y++;
	}
}

/*
** Draws vertical lines, starting from the ceiling, then walls and floor
*/

void			ver_line(t_wolf *w)
{
	long int	i;

	draw_ceiling(w);
	w->y = w->draw_start;
	while (w->y < w->draw_end)
	{
		grab_color(w);
		i = w->y * F_SW + w->x * 4;
		if (w->side == 1)
		{
			w->pxl[i] = (w->b2 >> 1) & 8355711;
			w->pxl[i + 1] = (w->g2 >> 1) & 8355711;
			w->pxl[i + 2] = (w->r2 >> 1) & 8355711;
		}
		else
		{
			w->pxl[i] = w->b2;
			w->pxl[i + 1] = w->g2;
			w->pxl[i + 2] = w->r2;
		}
		w->y++;
	}
	w->z_buf[w->x] = w->perp_wall_dist;
	draw_floor(w);
}
