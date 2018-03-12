/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_col_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:26:12 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/20 19:27:11 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	choose_txt(t_wolf *w)
{
	if (w->tex_num == 1)
		w->txt = w->wall_2;
	if (w->tex_num == 2)
		w->txt = w->wall_1;
	if (w->tex_num == 3)
		w->txt = w->wall;
	if (w->tex_num == 4)
		w->txt = w->wall_3;
	if (w->tex_num == 5)
		w->txt = w->box;
	if (w->tex_num == 6)
		w->txt = w->pic;
	if (w->tex_num == 7)
		w->txt = w->pic2;
	if (w->tex_num == 8)
		w->txt = w->gob;
	if (w->tex_num == 9)
		w->txt = w->hole;
	if (w->tex_num == 10)
		w->txt = w->eagle;
}

void	floor_manage(t_wolf *w)
{
	if (w->side == 0 && w->ray_dir_x > 0)
	{
		w->floor_x_wall = w->map_x;
		w->floor_y_wall = w->map_y + w->wall_x;
	}
	else if (w->side == 0 && w->ray_dir_x < 0)
	{
		w->floor_x_wall = w->map_x + 1.0;
		w->floor_y_wall = w->map_y + w->wall_x;
	}
	else if (w->side == 1 && w->ray_dir_y > 0)
	{
		w->floor_x_wall = w->map_x + w->wall_x;
		w->floor_y_wall = w->map_y;
	}
	else
	{
		w->floor_x_wall = w->map_x + w->wall_x;
		w->floor_y_wall = w->map_y + 1.0;
	}
	w->dist_wall = w->perp_wall_dist;
	w->dist_player = 0.0;
	if (w->draw_end < 0)
		w->draw_end = SCR_H;
}

void	grab_color(t_wolf *w)
{
	int	k;
	int	i;

	i = w->y * 64 - THT_SH + w->line_height * 32;
	w->text_y = ((i * w->tex_height) / w->line_height) / 64;
	w->pxl2 = mlx_get_data_addr(w->txt, &w->bpp2, &w->line2, &w->ed2);
	k = (w->tex_height * w->text_y + w->text_x) * 4;
	w->b2 = w->pxl2[k];
	w->g2 = w->pxl2[k + 1];
	w->r2 = w->pxl2[k + 2];
}

void	grab_color_floor(t_wolf *w)
{
	int	k;

	w->pxl2 = mlx_get_data_addr(w->txt2, &w->bpp2, &w->line2, &w->ed2);
	k = (w->tex_width * w->floor_tex_y + w->floor_tex_x) * 4;
	w->b2 = w->pxl2[k];
	w->g2 = w->pxl2[k + 1];
	w->r2 = w->pxl2[k + 2];
}
