/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:18:42 by liton             #+#    #+#             */
/*   Updated: 2016/12/24 21:13:56 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

int		search_place(char **map, t_ttmn *list)
{
	int		i;
	int		j;

	i = -1;
	if (!ttmn_in_map(map, list))
	{
		while (map[++i])
		{
			j = -1;
			while (map[i][++j])
			{
				if (map[i][j] == '.')
				{
					map = put_tetriminos(map, list, i, j);
					if (ttmn_in_map(map, list))
					{
						list->x = i;
						list->y = j;
						return (1);
					}
				}
			}
		}
	}
	return (0);
}
