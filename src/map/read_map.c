/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:15:51 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/13 13:57:10 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_raw_map(char *filename)
{
	char	*buf;
	char	*map;
	int		r_bytes;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	r_bytes = 1;
	map = NULL;
	while (r_bytes)
	{
		buf = ft_calloc(1, BUFFER_SIZE);
		if (!buf)
			return (free(map), NULL);
		r_bytes = read(fd, buf, BUFFER_SIZE);
		if (r_bytes == -1)
			return (free(map), NULL);
		buf[r_bytes] = '\0';
		map = ft_strjoin(map, buf);
		if (!map)
			return (NULL);
	}
	return (map);
}
