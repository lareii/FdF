/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:48:18 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/14 16:14:46 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "mlx.h"
#include <unistd.h>
#include <X11/keysym.h>

int	animation_loop(t_vars *vars)
{
	if (vars->is_animating)
	{
		mlx_clear_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr);
		vars->z_x_coef += 0.01;
		draw_background(vars);
		render_map(vars);
		mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr, vars->mlx->banner_img_ptr, 0, 0);
		usleep(10000);
	}
	return (1);
}

int	destroy_handler(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

static void	transformation_keys(int keycode, t_vars *vars)
{
	if (keycode == XK_e)
		vars->x_y_coef += 0.1;
	else if (keycode == XK_q)
		vars->x_y_coef -= 0.1;
	else if (keycode == XK_w)
		vars->y_z_coef += 0.1;
	else if (keycode == XK_s)
		vars->y_z_coef -= 0.1;
	else if (keycode == XK_a)
		vars->z_x_coef -= 0.1;
	else if (keycode == XK_d)
		vars->z_x_coef += 0.1;
	else if (keycode == XK_Right)
		vars->map_x += 5;
	else if (keycode == XK_Left)
		vars->map_x -= 5;
	else if (keycode == XK_Up)
		vars->map_y += 5;
	else if (keycode == XK_Down)
		vars->map_y -= 5;
}

static void	projection_keys(int keycode, t_vars *vars)
{
	if (keycode == XK_n)
		vars->zoom += 0.1;
	else if (keycode == XK_m && vars->zoom > 0.2)
		vars->zoom -= 0.1;
	else if (keycode == XK_j)
		vars->height -= 0.5;
	else if (keycode == XK_k)
		vars->height += 0.5;
	else if (keycode == XK_r)
	{
		vars->is_animating = 0;
		set_camera_props(vars);
	}
	else if (keycode == XK_t)
	{
		vars->is_animating = 0;
		vars->x_y_coef = 0;
		vars->y_z_coef = 0;
		vars->z_x_coef = 0;
	}
}

int	keypress_handler(int keycode, t_vars *vars)
{
	transformation_keys(keycode, vars);
	projection_keys(keycode, vars);
	if (keycode == XK_Escape)
	{
		vars->is_animating = 0;
		destroy_handler(vars->mlx);
	}
	else if (keycode == XK_space)
		vars->is_animating = !vars->is_animating;
	draw_background(vars);
	render_map(vars);
	mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr, vars->mlx->banner_img_ptr, 0, 0);
	return (0);
}
