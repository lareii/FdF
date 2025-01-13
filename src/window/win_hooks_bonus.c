/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:48:18 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/14 00:07:17 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"
#include "mlx.h"
#include <X11/keysym.h>

int	destroy_handler(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

int	key_handler(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		destroy_handler(mlx);
	return (0);
}
