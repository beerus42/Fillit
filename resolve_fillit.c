/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:18:42 by liton             #+#    #+#             */
/*   Updated: 2016/12/20 20:01:34 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

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

int		move_right(char **map, t_ttmn *list, int size_map, int *nb_t)
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

int		resolve_fillit_2(char **map, t_ttmn *list, int *nb_t)
{
	while (list->next && *nb_t)
	{
		if (search_place(map, list))
			if (list->next)
				list = list->next;
	}
}

int		put_max(char **map, t_ttmn **list, int *nb_t)
{
	while ((*list)->next && !ttmn_in_map(map, *list) && *nb_t)
	{
		if (!search_place(map, *list) && nb_t)
			return (0);
		*list = (*list)->next;
		--(*nb_t);
	}
	if (!search_place(map, *list))
		return (0);
	--(*nb_t);
	return (1);
}

char		**resolve_fillit(char **map, int nb_t, t_ttmn *list, int size_map)
{
	t_ttmn	*tmp;

	size_map = 5;
	put_max(map, &list, &nb_t);
	tmp = list->prev;
	while (nb_t)
	{
		while (nb_t && move_right(map, list->prev, size_map, &nb_t))
		{
			RR;
			ft_putchar('\n');
			resolve_fillit_2(&map, &list, &nb_t);
		}
		if (!ttmn_in_map(map, list) && nb_t)
		{
			if (list->letter != 'A')
				list = list->prev;
			remove_tetriminos(map, list);
		}
	}
	return (map);
}
