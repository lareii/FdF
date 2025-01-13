/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:39:50 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/13 22:32:51 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_renderer(t_vars *vars)
{
	set_camera_props(vars);
	render_map(vars);
}
