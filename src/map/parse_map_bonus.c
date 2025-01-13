/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:54:56 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/13 23:55:24 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static size_t	ulong_arr_len(unsigned long	*arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static unsigned long	get_point(char *point)
{
	unsigned long	ret;
	unsigned int	color;
	char			**point_attrs;
	int				z;

	point_attrs = ft_split(point, ',');
	if (!point_attrs)
		return (ULONG_MAX);
	z = ft_atoi(point_attrs[0]);
	if (!*(point_attrs + 1))
		color = DEFAULT_COLOR;
	else
		color = atoi_hex(point_attrs[1] + 2);
	ret = (((unsigned long)z) << 32) | (color);
	free_str_arr(point_attrs);
	return (ret);
}

static unsigned long	*get_map_row(char *map_row)
{
	unsigned long	*row;
	char			**str_row;
	size_t			row_len;
	size_t			i;

	str_row = ft_split(map_row, ' ');
	if (!str_row)
		return (NULL);
	row_len = ulong_arr_len((unsigned long *)str_row);
	row = malloc(sizeof(unsigned long) * (row_len + 1));
	if (!row)
	{
		free_str_arr(str_row);
		return (NULL);
	}
	i = 0;
	while (str_row[i])
	{
		row[i] = get_point(str_row[i]);
		i++;
	}
	row[row_len] = ULONG_MAX;
	free_str_arr(str_row);
	return (row);
}

unsigned long	**split_raw_map(char *raw_map)
{
	unsigned long	**map;
	char			**str_map;
	size_t			col_size;
	size_t			i;

	str_map = ft_split(raw_map, '\n');
	if (!str_map)
		return (NULL);
	col_size = ulong_arr_len((unsigned long *)str_map);
	map = malloc((col_size + 1) * sizeof(unsigned long *));
	if (!map)
	{
		free_str_arr(str_map);
		return (NULL);
	}
	i = 0;
	while (str_map[i])
	{
		map[i] = get_map_row(str_map[i]);
		i++;
	}
	map[col_size] = NULL;
	free_str_arr(str_map);
	return (map);
}
