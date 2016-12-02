/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:43:03 by liton             #+#    #+#             */
/*   Updated: 2016/12/02 16:52:11 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

char	**ft_map(void)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (29 + 1))))
		return (NULL);
	while (i < 29)
	{
		map[i] = ft_strnew(29);
		map[i] = ft_memset(map[i], '.', 29);
		i++;
	}
	map[i] = 0;
	return (map);
}
