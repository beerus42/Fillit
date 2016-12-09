/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:18:42 by liton             #+#    #+#             */
/*   Updated: 2016/12/09 18:19:49 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

char 	**resolve_fillit(char **map, int nb_t, tt_list *list)
{
	int			i;
	int			j;
	int			size_map;
	int			count;
	tt_list		*begin;

	i = 0;
	j = 0;
	count = 0;
	size_map = 5;
	begin = list;
	while (count != nb_t)
	{
		/*
		if (!map[i])
		{
			map = ft_map(size_map);
			i = 0;
			j = 0;
			count = 0;
			list = begin;
			size_map++;
		}
		*/
		if (map[i] && map[i][j] && map[i][j] == '.')
		{
			if (!ttmn_in_map(map, list))
				map = put_tetriminos(map, list, i, j);
			if (ttmn_in_map(map, list))
			{
				list = list->next;
				count++;
			}
			else
				j++;
		}
		else if (map[i] && map[i][j])
			j++;
		else if (!map[i][j])
		{
			j = 0;
			i++;
		}
		else if (!ttmn_in_map(map, list))
		{
			list = list->prev;
			map = remove_tetriminos(map, list);
			--count;
			list = list->next;
		}
	}
	return (map);
}
