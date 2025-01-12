/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:39:45 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/13 02:14:55 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

#include <stdio.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		ft_putendl_fd("Invalid arguments.\nUsage: ./fdf <map>", 2);
		return (1);
	}
	if (init_map(&vars, argv[1]) == -1)
		return (1);
	for (int i = 0; vars.map[i]; i++)
	{
		for (int j = 0; vars.map[i][j] != ULONG_MAX; j++)
		{
			printf("i: %d, j: %d, z: %lu, color: %lu \n", i, j, get_z(vars.map[i][j]), get_color(vars.map[i][j]));
		}
	}
	free_ulong_arr(vars.map);
}