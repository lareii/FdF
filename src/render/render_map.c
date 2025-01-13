/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:56:40 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/13 16:51:33 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <limits.h>

static void put_pixel(t_vars *vars, int x, int y, unsigned long color)
{
	int	i;

	if ((WIN_WIDTH / 2) + x >= 0
		&& abs((WIN_WIDTH / 2) + x) < WIN_WIDTH
		&& (WIN_HEIGHT / 2) + y >= 0
		&& abs((WIN_HEIGHT / 2)) + y < WIN_HEIGHT)
	{
		i = (((WIN_WIDTH / 2) + x) * vars->mlx->bits_per_pixel / 8)
			+ (((WIN_HEIGHT / 2) + y) * vars->mlx->size_line);
		vars->mlx->data_addr[i] = color;
		vars->mlx->data_addr[++i] = color >> 8;
		vars->mlx->data_addr[++i] = color >> 16;
	}
}

static void draw_line(t_vars *vars, t_point p1, t_point p2, unsigned long color)
{
	double x0;
	double y0;
	int	steps;
	int	i;

	x0 = p1.x;
	y0 = p1.y;
	steps = abs(p2.y - p1.y);
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		steps = abs(p2.x - p1.x);
	i = 0;
	while (i <= steps)
	{
		put_pixel(vars, (int)x0, (int)y0, color);
		x0 += (p2.x - p1.x) / (double)steps;
		y0 += (p2.y - p1.y) / (double)steps;
		i++;
	}
}

static void	set_lines(t_vars *vars, int x, int y, unsigned long point)
{
	t_point	left_point;
	t_point	top_point;
	t_point	curr_point;

	set_point(&curr_point, x, y, get_z(point));
	render_point(vars, &curr_point);
	if (x > 0)
	{
		set_point(&left_point, x - 1, y, get_z(vars->map[y][x - 1]));
		render_point(vars, &left_point);
		draw_line(vars, curr_point, left_point, get_color(vars->map[y][x - 1]));
	}
	if (y > 0)
	{
		set_point(&top_point, x, y - 1, get_z(vars->map[y - 1][x]));
		render_point(vars, &top_point);
		draw_line(vars, curr_point, top_point, get_color(vars->map[y - 1][x]));
	}
}

void	render_map(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != ULONG_MAX)
		{
			set_lines(vars, j, i, vars->map[i][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr,
		vars->mlx->img_ptr, 0, 0);
}

