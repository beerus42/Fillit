/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:18:42 by liton             #+#    #+#             */
/*   Updated: 2016/12/16 05:20:55 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

int		search_place(char ****map, t_ttmn *list)
{
	int		i;
	int		j;

	i = -1;
	if (!ttmn_in_map(**map, list))
	{	
		while ((**map)[++i])
		{
			j = -1;
			while ((**map)[i][++j])
			{
				if ((**map)[i] && (**map)[i][j] && (**map)[i][j] == '.')
				{
					**map = put_tetriminos(**map, list, i, j);
					if (ttmn_in_map(**map, list))
						return (1);
				}
			}
		}
	}
	return (0);
}

int		last_ttmn(t_ttmn *list, char **map, t_ttmn *begin)
{
	int		last;
	t_ttmn 	*tmp;

	last = 0;
	list = begin;
	while (list)
	{
		if (!ttmn_in_map(map, list))
		{
			if (list->nb == 1)
				tmp = list;
			if (last < list->nb)
				last = list->nb;
		}
		list = list->next;
	}
	list = begin;
	return (last);
}

int		put_in_order(char ***map, t_ttmn **list, int *count, t_ttmn *begin)
{
	int		cnt;
	int		last;
	int		order;

	cnt = 0;
	*list = begin;
	order = 1;
	last = last_ttmn(*list, *map, begin);
	while (cnt != last)
	{
		while (((*list)->next && ttmn_in_map(*map, *list)) || (*list)->nb != order)
			*list = (*list)->next;
		if (search_place(&map, *list))
		{
			*list = begin;
			++(*count);
			++order;
			cnt++;
		}
		else
			return (0);
	}
	return (1);
}

t_ttmn 		*change_order(char **map, t_ttmn *list, t_ttmn *begin)
{
	int		order;

	order = 1;
	list = begin;
	while (list)
	{
		if (!ttmn_in_map(map, list))
			list->nb = order++;
		list = list->next;
	}
	list = begin;
	return (list);
}

char		**resolve_fillit(char **map, int nb_t, t_ttmn *list)
{
	int			size_map;
	t_ttmn		*begin;
	int			count;

	begin = list;
	size_map = 5;
	count = 0;
	while (count != nb_t)
	{
		if (!put_in_order(&map, &list, &count, begin))
		{
			list = change_order(map, list, begin);
		}
	}
	return (map);
}
