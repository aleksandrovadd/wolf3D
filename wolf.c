/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:27:35 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/20 19:28:25 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			wolf_init(t_wolf *w)
{
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, SCR_W, SCR_H, "Wolf3D");
	w->img = mlx_new_image(w->mlx, SCR_W, SCR_H);
	w->pxl = mlx_get_data_addr(w->img, &w->bpp, &w->line, &w->ed);
	init_param(w);
	init_texture(w);
	mlx_hook(w->win, 2, 5, key_hook, w);
	mlx_hook(w->win, 17, 0L, ft_mouse_hook, 0);
	draw_wolf(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	mlx_loop_hook(w->mlx, funct, w);
	mlx_loop(w->mlx);
	return (0);
}

int			main(void)
{
	t_wolf	*w;

	w = (t_wolf *)malloc(sizeof(t_wolf));
	read_map(w);
	wolf_init(w);
	return (0);
}
