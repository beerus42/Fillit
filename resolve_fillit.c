/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:18:42 by liton             #+#    #+#             */
/*   Updated: 2016/12/24 18:02:11 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

int			search_place(char **map, t_ttmn *list)
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
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int			put_max(char **map, t_ttmn **list, int *nb_t)
{
	while ((*list)->next && !ttmn_in_map(map, *list) && *nb_t)
	{
		if (*nb_t && !search_place(map, *list))
			return (0);
		*list = (*list)->next;
		--(*nb_t);
	}
	if (!search_place(map, *list))
		return (0);
	--(*nb_t);
	return (1);
}

int			resolve_fillit_2(char **map, int *nb_t, t_ttmn *list, int size_map)
{
	t_ttmn 		*tmp;

	if (!search_place(map, list))
		return (0);
	--(*nb_t);
	tmp = list;
	if (list->next)
		list = list->next;
	while (*nb_t)
	{
		if (*nb_t && search_place(map, list) && (*nb_t)--)
		{
			if (list->next)
				list = list->next;
			else
				return (1);
		}
		else if (!move_right(map, list->prev, size_map, nb_t))
		{
			if (list->prev == tmp)
				return (0);
			list = list->prev;
			while (list->prev != tmp && !move_right(map, list->prev, size_map, nb_t))
				list = list->prev;
			if (list->prev == tmp && !move_right(map, list->prev, size_map, nb_t))
				return (0);
		}
	}
	return (1);
}

char		**resolve_fillit(char **map, int nb_t, t_ttmn *list, int size_map)
{
	t_ttmn	*begin;

	begin = list;
	put_max(map, &list, &nb_t);
	while (nb_t && list == begin)
	{
		size_map++;
		free(map);
		map = ft_map(size_map);
		put_max(map, &list, &nb_t);
	}
	while (nb_t)
	{
		while (nb_t && move_right(map, list->prev, size_map, &nb_t))
		{
			if (resolve_fillit_2(map, &nb_t, list, size_map))
				return (map);
		}
		if (nb_t && list->prev->letter == 'A')
		{
			free(map);
			size_map++;
			map = ft_map(size_map);
			list = begin;
			put_max(map, &list, &nb_t);
		}
		else if (!ttmn_in_map(map, list) && nb_t)
			list = list->prev;
	}
	return (map);
}
