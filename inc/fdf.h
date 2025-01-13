/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:28:32 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/13 14:29:13 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "window.h"
# include <stddef.h>

# define BUFFER_SIZE 99999
# define COLOR_MASK 4294967295U
# define DEFAULT_COLOR 0x00FFFFFF

typedef struct s_vars
{
	t_mlx			*mlx;

	unsigned long	**map;
	size_t			col_size;
	size_t			row_size;

	size_t			anchor_x;
	size_t			anchor_y;
}				t_vars;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

int				init_map(t_vars *vars, char *filename);
char			*get_raw_map(char *filename);
unsigned long	**split_raw_map(char *raw_map);

void			free_str_arr(char	**arr);
void			free_ulong_arr(unsigned long **arr);

unsigned long	get_z(unsigned long point);
unsigned long	get_color(unsigned long point);
unsigned int	ft_atoi_hex(char *str);

int				init_win(t_vars *vars);
void			destroy_win(t_mlx *mlx);
int				destroy_handler(t_mlx *mlx);
int				key_handler(int keycode, t_mlx *mlx);

#endif