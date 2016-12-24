/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:18:42 by liton             #+#    #+#             */
/*   Updated: 2016/12/24 21:13:35 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

int			move_right(char **map, t_ttmn *list, int size_map, int *nb_t)
{
	int		i;
	int		j;

	i = list->x;
	j = list->y + 1;
	map = remove_tetriminos(map, list);
	++(*nb_t);
	while (i < size_map)
	{
		while (j < size_map)
		{
			map = put_tetriminos(map, list, i, j);
			if (ttmn_in_map(map, list))
			{
				--(*nb_t);
				list->x = i;
				list->y = j;
				return (1);
			}
			++j;
		}
		j = 0;
		++i;
	}
	return (0);
}
