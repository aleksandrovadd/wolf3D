/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:51:06 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/20 18:53:24 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	sprite_width(t_wolf *w)
{
	w->spr_wth = fabs((int)SCR_H / (w->tr_y));
	w->dr_st_x = -(w->spr_wth) / 2 + w->spr_scr_x;
	if (w->dr_st_x < 0)
		w->dr_st_x = 0;
	w->dr_e_x = w->spr_wth / 2 + w->spr_scr_x;
	if (w->dr_e_x >= SCR_W)
		w->dr_e_x = SCR_W - 1;
}

void	draw_pixel(t_wolf *w, int k)
{
	int i;

	if (w->pxl3[k + 3] >= 0)
	{
		w->b3 = w->pxl3[k];
		w->g3 = w->pxl3[k + 1];
		w->r3 = w->pxl3[k + 2];
		i = w->y * F_SW + w->stripe * 4;
		w->pxl[i] = w->b3;
		w->pxl[i + 1] = w->g3;
		w->pxl[i + 2] = w->r3;
	}
}

void	draw_sprite(t_wolf *w)
{
	int	i;
	int	k;

	w->stripe = w->dr_st_x;
	while (w->stripe < w->dr_e_x)
	{
		w->tex_x = (int)(256 * (w->stripe - (-w->spr_wth / 2 + w->spr_scr_x))
		* w->tex_width / w->spr_wth) / 256;
		if (w->tr_y > 0 && w->stripe > 0 && w->stripe < SCR_W &&
		w->tr_y < w->z_buf[w->stripe])
		{
			w->y = w->dr_st_y;
			while (w->y < w->dr_e_y)
			{
				i = w->y * 64 - THT_SH + w->spr_h * 32;
				w->tex_y = ((i * w->tex_height) / w->spr_h) / 64;
				w->pxl3 = mlx_get_data_addr(w->txt_spr, &w->bpp3,
				&w->line3, &w->ed3);
				k = (w->tex_width * w->tex_y + w->tex_x) * 4;
				draw_pixel(w, k);
				w->y++;
			}
		}
		w->stripe++;
	}
}

void	projection_sprites(t_wolf *w)
{
	int	i;

	i = 0;
	while (i < NUM_SPR)
	{
		w->sprite_x = w->spr_map[w->spr_order[i]][0] - w->pos_x;
		w->sprite_y = w->spr_map[w->spr_order[i]][1] - w->pos_y;
		w->inv_det = 1.0 / (w->plane_x * w->dir_y - w->dir_x * w->plane_y);
		w->tr_x = w->inv_det * (w->dir_y * w->sprite_x - w->dir_x
		* w->sprite_y);
		w->tr_y = w->inv_det * (-(w->plane_y) * w->sprite_x + w->plane_x
		* w->sprite_y);
		w->spr_scr_x = (int)((H_SCR_W) * (1 + w->tr_x / w->tr_y));
		w->spr_h = abs((int)(SCR_H / (w->tr_y)));
		w->dr_st_y = -(w->spr_h) / 2 + H_SCR_H;
		if (w->dr_st_y < 0)
			w->dr_st_y = 0;
		w->dr_e_y = w->spr_h / 2 + H_SCR_H;
		if (w->dr_e_y >= SCR_H)
			w->dr_e_y = SCR_H - 1;
		choose_sprite(w, i);
		sprite_width(w);
		draw_sprite(w);
		i++;
	}
}

void	sprite_casting(t_wolf *w)
{
	int	i;

	i = 0;
	while (i < NUM_SPR)
	{
		w->spr_order[i] = i;
		w->spr_dist[i] = ((w->pos_x - w->spr_map[i][0]) *
		(w->pos_x - w->spr_map[i][0]) + (w->pos_y - w->spr_map[i][1])
		* (w->pos_y - w->spr_map[i][1]));
		i++;
	}
	comb_sort(w);
	projection_sprites(w);
}
