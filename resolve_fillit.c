/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:18:42 by liton             #+#    #+#             */
/*   Updated: 2016/12/12 18:34:57 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

char	**resolve_fillit(char **map, int nb_t, tt_list *list)
{
	int			i;
	int			j;
	int			count;
	tt_list		*begin;

	begin = list;
	count = 0;
	while (count != nb_t)
	{
		i = 0;
		while (map[i] && count != nb_t)
		{
			j = 0;
			while (map[i][j] && count != nb_t)
			{
				if (map[i] && map[i][j] && map[i][j] == '.')
				{
					if (!ttmn_in_map(map, list))
						map = put_tetriminos(map, list, i, j);
					if (ttmn_in_map(map, list))
					{
						if (list->next)
							list = list->next;
						++count;
					}
				}
				++j;
			}
			++i;
		}
			if (!ttmn_in_map(map, list))
			{
				list = list->next;
				i = 0;
				j = 0;
			}
	}
	return (map);
}
/*
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
		if (!map[i])
		{
			map = ft_map(size_map);
			i = 0;
			j = 0;
			count = 0;
			list = begin;
			size_map++;
		}
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
*/
