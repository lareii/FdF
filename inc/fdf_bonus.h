/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:44:47 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/14 02:07:50 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "window_bonus.h"
# include <stddef.h>

# define BUFFER_SIZE 99999

# define COLOR_MASK 4294967295U
# define LINE_COLOR 0x00D4D4D8
# define BG_COLOR 0x0009090B

typedef struct s_vars
{
	t_mlx			*mlx;

	unsigned long	**map;
	int				col_size;
	int				row_size;

	int				anchor_x;
	int				anchor_y;
	int				map_x;
	int				map_y;

	double			distance;
	double			height;
	double			zoom;
	double			x_y_coef;
	double			y_z_coef;
	double			z_x_coef;

	int				is_animating;
}	t_vars;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

int				init_map(t_vars *vars, char *filename);
char			*get_raw_map(char *filename);
unsigned long	**split_raw_map(char *raw_map);

void			init_renderer(t_vars *vars);
void			render_map(t_vars *vars);
void			set_camera_props(t_vars *vars);
void			set_point(t_point *point, int x, int y, int z);
void			render_point(t_vars *vars, t_point *point);
void			zoom(t_vars *vars, t_point *point);
void			translate(t_vars *vars, t_point *point);
void			rotate_z_x(t_vars *vars, t_point *point);
void			rotate_y_z(t_vars *vars, t_point *point);
void			rotate_x_y(t_vars *vars, t_point *point);

void			draw_background(t_vars *vars);
int				init_win(t_vars *vars);
void			destroy_win(t_mlx *mlx);
int				destroy_handler(t_mlx *mlx);
int				keypress_handler(int keycode, t_vars *vars);
int				animation_loop(t_vars *vars);

void			free_str_arr(char **arr);
void			free_ulong_arr(unsigned long **arr);
unsigned long	get_z(unsigned long point);
unsigned long	get_color(unsigned long point);
unsigned int	atoi_hex(char *str);
int				abs(int n);

#endif