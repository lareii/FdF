/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:41:23 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/14 00:24:49 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "window.h"
#include "mlx.h"
#include <stdlib.h>

void	draw_background(t_vars *vars)
{
	int	*background;
	int	i;

	background = (int *)(vars->mlx->data_addr);
	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH)
	{
		background[i] = BG_COLOR;
		i++;
	}
}

void	destroy_win(t_mlx *mlx)
{
	if (mlx->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
}
