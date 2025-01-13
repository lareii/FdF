/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:39:45 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/13 13:53:37 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

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
	if (init_win(&vars) == -1)
		return (1);
	free_ulong_arr(vars.map);
}
