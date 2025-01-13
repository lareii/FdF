/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:20:27 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/13 13:54:31 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <limits.h>

static void	init_map_props(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (vars->map[0][i] != ULONG_MAX)
		i++;
	vars->row_size = i;
	vars->anchor_x = i / 2;
	i = 0;
	while (vars->map[i])
		i++;
	vars->col_size = i;
	vars->anchor_y = i / 2;
}

int	init_map(t_vars *vars, char *filename)
{
	char	*raw_map;

	raw_map = get_raw_map(filename);
	if (!raw_map)
		return (-1);
	vars->map = split_raw_map(raw_map);
	if (!vars->map)
		return (-1);
	free(raw_map);
	init_map_props(vars);
	return (0);
}
