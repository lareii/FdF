/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:11 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/13 16:11:13 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	zoom(t_vars *vars, t_point *point)
{
	point->x *= vars->zoom;
	point->y *= vars->zoom;
	point->z *= vars->zoom;
}

void	translate(t_vars *vars, t_point *point)
{
	point->x += vars->map_x;
	point->y -= vars->map_y;
}

void	rotate_z_x(t_vars *vars, t_point *point)
{
	double	original_z;

	original_z = point->z;
	point->z = original_z * cos(vars->z_x_coef)
		+ point->x * -sin(vars->z_x_coef);
	point->x = original_z * sin(vars->z_x_coef)
		+ point->x * cos(vars->z_x_coef);
}

void	rotate_y_z(t_vars *vars, t_point *point)
{
	double	original_y;

	original_y = point->y;
	point->y = point->z * sin(vars->y_z_coef)
		+ original_y * cos(vars->y_z_coef);
	point->z = point->z * cos(vars->y_z_coef)
		+ original_y * -sin(vars->y_z_coef);
}

void	rotate_x_y(t_vars *vars, t_point *point)
{
	double	original_x;

	original_x = point->x;
	point->x = original_x * cos(vars->x_y_coef)
		+ point->y * -sin(vars->x_y_coef);
	point->y = original_x * sin(vars->x_y_coef)
		+ point->y * cos(vars->x_y_coef);
}
