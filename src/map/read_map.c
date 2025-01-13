/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:15:51 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/13 14:39:55 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	read_file(int fd, char **map, char **buf)
{
	ssize_t	r_bytes;

	r_bytes = 1;
	*map = NULL;
	while (r_bytes)
	{
		*buf = ft_calloc(1, BUFFER_SIZE + 1);
		if (!*buf)
		{
			free(*map);
			return (-1);
		}
		r_bytes = read(fd, *buf, BUFFER_SIZE);
		if (r_bytes == -1)
		{
			free(*map);
			free(*buf);
			return (-1);
		}
		(*buf)[r_bytes] = '\0';
		*map = ft_strjoin(*map, *buf);
		if (!*map)
			return (-1);
	}
	return (0);
}

char	*get_raw_map(char *filename)
{
	char	*buf;
	char	*map;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (read_file(fd, &map, &buf) == -1)
		return (NULL);
	return (map);
}
