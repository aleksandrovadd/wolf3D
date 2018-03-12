/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_cast_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:55:13 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/20 19:18:27 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	choose_sprite(t_wolf *w, int i)
{
	if (w->spr_map[i][2] == 11)
		w->txt_spr = w->gr_light;
	if (w->spr_map[i][2] == 13)
		w->txt_spr = w->barrel;
}

void	swap_double(double inf, double chan)
{
	double	temp;

	temp = inf;
	inf = chan;
	chan = temp;
}

void	swap_int(int inf, int chan)
{
	int	temp;

	temp = inf;
	inf = chan;
	chan = temp;
}

void	sort_comb(t_wolf *w, int *t, int gap)
{
	int	i;
	int j;

	i = 0;
	while (i < NUM_SPR - gap)
	{
		j = i + gap;
		if (w->spr_dist[i] < w->spr_dist[j])
		{
			swap_double(w->spr_dist[i], w->spr_dist[j]);
			swap_int(w->spr_order[i], w->spr_order[j]);
			*t = 1;
		}
		i++;
	}
}

void	comb_sort(t_wolf *w)
{
	int gap;
	int t;

	gap = NUM_SPR;
	t = 0;
	while (gap > 1 || t == 0)
	{
		gap = (gap * 10) / 13;
		if (gap == 9 || gap == 10)
			gap = 11;
		if (gap < 1)
			gap = 1;
		t = 0;
		sort_comb(w, &t, gap);
	}
}
