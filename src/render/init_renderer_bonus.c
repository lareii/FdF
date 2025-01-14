/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_renderer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:53:01 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/14 17:04:37 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "mlx.h"

void	init_renderer(t_vars *vars)
{
	set_camera_props(vars);
	draw_background(vars);
	render_map(vars);
	mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr,
		vars->mlx->banner_img_ptr, 0, 0);
}
