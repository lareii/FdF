/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:28:32 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/13 02:14:26 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "window.h"
# include <stddef.h>

# define BUFFER_SIZE 99999
# define COLOR_MASK 4294967295U
# define DEFAULT_COLOR 0x00FFFFFF

typedef struct	s_vars
{
	t_mlx			*mlx;

	unsigned long	**map;
	size_t			col_size;
	size_t			row_size;
}				t_vars;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

int		init_map(t_vars *vars, char *filename);
void	free_str_arr(char	**arr);
void	free_ulong_arr(unsigned long **arr);
size_t	ulong_arr_len(unsigned long	*arr);
unsigned long	get_z(unsigned long point);
unsigned long	get_color(unsigned long point);
unsigned int	ft_atoi_hex(char *str);

#endif