/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_tetriminos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:52:21 by liton             #+#    #+#             */
/*   Updated: 2016/12/25 05:10:29 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

char	**remove_tetriminos(char **map, t_ttmn *list)
{
	int		i;
	int		j;
	int		size_map;

	size_map = ft_strlen(map[0]);
	i = -1;
	while (++i < size_map)
	{
		j = -1;
		while (++j < size_map)
		{
			if (map[i][j] == list->letter)
				map[i][j] = '.';
		}
	}
	return (map);
}
