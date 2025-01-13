/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:10:17 by ebabaogl          #+#    #+#             */
/*   Updated: 2025/01/13 22:33:12 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

unsigned int	atoi_hex(char *str)
{
	unsigned int	res;
	int				val;

	res = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			val = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			val = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			val = *str - 'A' + 10;
		res = res * 16 + val;
		str++;
	}
	return (res);
}

void	free_ulong_arr(unsigned long **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_str_arr(char	**arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
