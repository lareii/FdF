/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:53:45 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/13 23:53:51 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

unsigned long	get_z(unsigned long point)
{
	return (point >> 32);
}

unsigned long	get_color(unsigned long point)
{
	return (point & COLOR_MASK);
}

void	set_camera_props(t_vars *vars)
{
	double	width_distance;
	double	height_distance;

	width_distance = (double)(PADDED_WIDTH) / (vars->row_size);
	height_distance = (double)(PADDED_HEIGHT) / (vars->col_size);
	if (width_distance > height_distance)
		vars->distance = height_distance;
	else
		vars->distance = width_distance;
	vars->height = 5;
	vars->zoom = 0.7;
	vars->x_y_coef = -0.4;
	vars->y_z_coef = -0.9;
	vars->z_x_coef = 0;
	vars->map_x = 0;
	vars->map_y = 0;
}

void	set_point(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

void	render_point(t_vars *vars, t_point *point)
{
	point->x = (point->x - vars->anchor_x) * vars->distance;
	point->y = (point->y - vars->anchor_y) * vars->distance;
	point->z = point->z * vars->height;
	rotate_x_y(vars, point);
	rotate_y_z(vars, point);
	rotate_z_x(vars, point);
	translate(vars, point);
	zoom(vars, point);
}
