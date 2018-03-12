/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:36:20 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/20 18:40:22 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	redraw_wolf(t_wolf *w)
{
	mlx_destroy_image(w->mlx, w->img);
	w->img = mlx_new_image(w->mlx, SCR_W, SCR_H);
	w->pxl = mlx_get_data_addr(w->img, &w->bpp, &w->line, &w->ed);
	draw_wolf(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
}

int		init_param(t_wolf *w)
{
	w->color = 0;
	w->pos_x = 18;
	w->pos_y = 9.5;
	w->dir_x = -1;
	w->dir_y = 0;
	w->plane_x = 0;
	w->plane_y = 0.58;
	w->tex_width = 64;
	w->tex_height = 64;
	return (0);
}

int		init_texture_2(t_wolf *w)
{
	w->gob = mlx_xpm_file_to_image(w->mlx, "pics/rsz_gw610.XPM",
	&w->tex_width, &w->tex_height);
	w->hole = mlx_xpm_file_to_image(w->mlx, "pics/rsz_gw310.XPM",
	&w->tex_width, &w->tex_height);
	w->eagle = mlx_xpm_file_to_image(w->mlx, "pics/eagle.XPM",
	&w->tex_width, &w->tex_height);
	w->barrel = mlx_xpm_file_to_image(w->mlx, "pics/oie_transparent.XPM",
	&w->tex_width, &w->tex_height);
	w->gr_light = mlx_xpm_file_to_image(w->mlx, "pics/oie_greenlight.XPM",
	&w->tex_width, &w->tex_height);
	return (0);
}

int		init_texture(t_wolf *w)
{
	w->wall = mlx_xpm_file_to_image(w->mlx, "pics/bluestone.XPM",
	&w->tex_width, &w->tex_height);
	w->box = mlx_xpm_file_to_image(w->mlx, "pics/wood.XPM",
	&w->tex_width, &w->tex_height);
	w->wall_2 = mlx_xpm_file_to_image(w->mlx, "pics/greystone.XPM",
	&w->tex_width, &w->tex_height);
	w->wall_3 = mlx_xpm_file_to_image(w->mlx, "pics/redbrick.XPM",
	&w->tex_width, &w->tex_height);
	w->floor = mlx_xpm_file_to_image(w->mlx, "pics/64x64_black-tile-floor.XPM",
	&w->tex_width, &w->tex_height);
	w->pic = mlx_xpm_file_to_image(w->mlx, "pics/rsz_gw710.XPM",
	&w->tex_width, &w->tex_height);
	w->pic2 = mlx_xpm_file_to_image(w->mlx, "pics/rsz_gw810.XPM",
	&w->tex_width, &w->tex_height);
	w->wall_1 = mlx_xpm_file_to_image(w->mlx, "pics/rsz_gw110.XPM",
	&w->tex_width, &w->tex_height);
	init_texture_2(w);
	return (0);
}
