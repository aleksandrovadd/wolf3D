/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_wolf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:48:34 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/20 18:50:38 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	choose_colors(t_wolf *w)
{
	w->tex_num = w->world_map[w->map_x][w->map_y];
	choose_txt(w);
	if (w->side == 0)
		w->wall_x = w->ray_pos_y + w->perp_wall_dist * w->ray_dir_y;
	else
		w->wall_x = w->ray_pos_x + w->perp_wall_dist * w->ray_dir_x;
	w->wall_x -= floor(w->wall_x);
	w->text_x = (int)(w->wall_x * (double)w->tex_width);
	if (w->side == 0 && w->ray_dir_x > 0)
		w->text_x = w->tex_width - w->text_x - 1;
	if (w->side == 1 && w->ray_dir_y < 0)
		w->text_x = w->tex_width - w->text_x - 1;
	ver_line(w);
}

void	print_lines(t_wolf *w)
{
	if (w->side == 0)
		w->perp_wall_dist = (w->map_x - w->ray_pos_x + (1 - w->step_x)
		/ 2) / w->ray_dir_x;
	else
		w->perp_wall_dist = (w->map_y - w->ray_pos_y + (1 - w->step_y)
		/ 2) / w->ray_dir_y;
	w->line_height = (int)(SCR_H / w->perp_wall_dist);
	w->draw_start = -(w->line_height) / 2 + H_SCR_H;
	if (w->draw_start < 0)
		w->draw_start = 0;
	w->draw_end = w->line_height / 2 + H_SCR_H;
	if (w->draw_end >= SCR_H)
		w->draw_end = SCR_H - 1;
	choose_colors(w);
}

void	change_steps(t_wolf *w)
{
	if (w->ray_dir_x < 0)
	{
		w->step_x = -1;
		w->side_dist_x = (w->ray_pos_x - w->map_x) * w->delta_dist_x;
	}
	else
	{
		w->step_x = 1;
		w->side_dist_x = (w->map_x + 1.0 - w->ray_pos_x) * w->delta_dist_x;
	}
	if (w->ray_dir_y < 0)
	{
		w->step_y = -1;
		w->side_dist_y = (w->ray_pos_y - w->map_y) * w->delta_dist_y;
	}
	else
	{
		w->step_y = 1;
		w->side_dist_y = (w->map_y + 1.0 - w->ray_pos_y) * w->delta_dist_y;
	}
}

void	choose_side(t_wolf *w)
{
	while (w->hit == 0)
	{
		if (w->side_dist_x < w->side_dist_y)
		{
			w->side_dist_x += w->delta_dist_x;
			w->map_x += w->step_x;
			w->side = 0;
		}
		else
		{
			w->side_dist_y += w->delta_dist_y;
			w->map_y += w->step_y;
			w->side = 1;
		}
		if (w->world_map[w->map_x][w->map_y] > 0)
			w->hit = 1;
	}
}

void	draw_wolf(t_wolf *w)
{
	w->x = 0;
	while (w->x < SCR_W)
	{
		w->camera_x = 2 * w->x / (double)SCR_W - 1;
		w->ray_pos_x = w->pos_x;
		w->ray_pos_y = w->pos_y;
		w->ray_dir_x = w->dir_x + w->plane_x * w->camera_x;
		w->ray_dir_y = w->dir_y + w->plane_y * w->camera_x;
		w->map_x = (int)w->ray_pos_x;
		w->map_y = (int)w->ray_pos_y;
		w->delta_dist_x = sqrt(1 + (w->ray_dir_y * w->ray_dir_y)
		/ (w->ray_dir_x * w->ray_dir_x));
		w->delta_dist_y = sqrt(1 + (w->ray_dir_x * w->ray_dir_x)
		/ (w->ray_dir_y * w->ray_dir_y));
		w->hit = 0;
		change_steps(w);
		choose_side(w);
		print_lines(w);
		w->x++;
	}
}
