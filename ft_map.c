/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:43:03 by liton             #+#    #+#             */
/*   Updated: 2016/12/12 16:21:16 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

char	**ft_map(int size)
{
	char	**map;
	int		i;

	i = -1;
	if (!(map = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (++i < size)
	{
		map[i] = ft_strnew(size);
		map[i] = ft_memset(map[i], '.', size);
	}
	map[i] = 0;
	return (map);
}
