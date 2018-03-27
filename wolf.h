/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:33:46 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/20 19:55:10 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft/libft.h"
# include "ft_printf/src/ft_printf.h"
# define SCR_W 1200
# define SCR_H 800
# define UP_KEY 126
# define R_KEY 124
# define D_KEY 125
# define L_KEY 123
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define MAP_WIDTH 20
# define MAP_HEIGHT 20
# define ANGLE (5 * M_PI / 180)
# define NUM_SPR 9
# define H_SCR_H (SCR_H / 2)
# define H_SCR_W (SCR_W / 2)
# define F_SW (SCR_W * 4)
# define THT_SH (SCR_H * 32)

typedef struct		s_wolf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pxl;
	void			*txt;
	void			*txt2;
	void			*txt_spr;

	int				bpp;
	int				line;
	int				ed;

	char			*pxl2;
	int				bpp2;
	int				line2;
	int				ed2;

	void			*floor;
	void			*wall;
	void			*wall_1;
	void			*wall_2;
	void			*wall_3;
	void			*box;
	void			*pic;
	void			*pic2;
	void			*gob;
	void			*hole;
	void			*eagle;
	void			*pillar;
	int				color;

	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			old_dir_x;
	double			old_plane_x;
	int				x;
	int				y;

	int				tex_num;
	double			wall_x;
	int				text_x;
	int				text_y;

	int				r2;
	int				g2;
	int				b2;

	int				tex_width;
	int				tex_height;

	double			floor_x_wall;
	double			floor_y_wall;
	double			dist_wall;
	double			dist_player;
	double			current_dist;
	double			weight;
	double			current_floor_x;
	double			current_floor_y;
	int				floor_tex_x;
	int				floor_tex_y;

	int				world_map[MAP_WIDTH][MAP_HEIGHT];
	double			spr_map[NUM_SPR][3];
	double			z_buf[SCR_W];
}					t_wolf;

int					init_param(t_wolf *w);
int					init_texture(t_wolf *w);
int					wolf_init(t_wolf *w);

int					read_map(t_wolf *w);
void				free_split(char **str);
void				parse_map(t_wolf *w, char *line, int y);

void				parse_sprites(t_wolf *w, char *line, int y);
int					read_sprites(t_wolf *w);

void				draw_wolf(t_wolf *w);
void				choose_side(t_wolf *w);
void				change_steps(t_wolf *w);
void				print_lines(t_wolf *w);
void				choose_colors(t_wolf *w);
void				choose_txt(t_wolf *w);
void				ver_line(t_wolf *w);
void				grab_color(t_wolf *w);
void				grab_color_floor(t_wolf *w);
void				draw_ceiling(t_wolf *w);
void				draw_floor(t_wolf *w);
void				floor_manage(t_wolf *w);

int					ft_mouse_hook(void);
void				change_angle_left(t_wolf *w);
void				change_angle_right(t_wolf *w);
int					key_hook(int key, t_wolf *w);
int					funct(t_wolf *w);
void				redraw_wolf(t_wolf *w);

#endif
