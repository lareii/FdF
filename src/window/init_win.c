/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:39:33 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/13 22:28:58 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <X11/Xlib.h>
#include <stdlib.h>

static int	set_img_props(t_mlx *mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img_ptr)
	{
		destroy_win(mlx);
		return (-1);
	}
	mlx->data_addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	if (!mlx->data_addr)
	{
		destroy_win(mlx);
		return (-1);
	}
	return (0);
}

static int	set_win_props(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		destroy_win(mlx);
		return (-1);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!mlx->win_ptr)
	{
		destroy_win(mlx);
		return (-1);
	}
	return (0);
}

int	init_win(t_vars *vars)
{
	t_mlx	mlx;

	vars->mlx = &mlx;
	mlx.mlx_ptr = NULL;
	mlx.win_ptr = NULL;
	mlx.img_ptr = NULL;
	if (set_win_props(vars->mlx) == -1)
		return (-1);
	if (set_img_props(vars->mlx) == -1)
		return (-1);
	mlx_hook(mlx.win_ptr, DestroyNotify, 0, destroy_handler, &mlx);
	mlx_key_hook(mlx.win_ptr, key_handler, &mlx);
	init_renderer(vars);
	mlx_loop(mlx.mlx_ptr);
	destroy_win(&mlx);
	return (0);
}
