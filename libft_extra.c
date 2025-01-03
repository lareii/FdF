#include "libft.h"
#include <stdio.h>

unsigned int	ft_atoi_hex(char *str)
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

size_t	ft_ptrarrlen(unsigned long	*arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}