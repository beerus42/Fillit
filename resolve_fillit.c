/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:18:42 by liton             #+#    #+#             */
/*   Updated: 2016/12/17 03:49:25 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

#define RR ft_display_tab(map) 

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
				if (map[i] && map[i][j] && map[i][j] == '.')
				{
					map = put_tetriminos(map, list, i, j);
					if (ttmn_in_map(map, list))
					{	
						RR;
						ft_putchar('\n');
						return (1);
					}
				}
//				ft_display_tab(map);
//				ft_putchar('\n');
			}
		}
	}
	return (0);
}

int		put_max(char **map, t_ttmn **list, int *nb_t)
{
	while ((*list) && !ttmn_in_map(map, *list))
	{
		if(!search_place(map, *list))
			return (0);
		*list = (*list)->next;
		--(*nb_t);
	}
	return (1);
}

char	**reset_change_order(char **map, int **nb_t, t_ttmn **save, t_ttmn ***list)
{
	while ((**list)->next && ttmn_in_map(map, **list))
	{
	
		map = remove_tetriminos(map, **list);
		++(**nb_t);
		**list = (**list)->next;
	}
	if ((*save)->next)
		*save = (*save)->next;
	**list = *save;
	return (map);
}

char		**reset(char **map, int **nb_t, t_ttmn *tmp, t_ttmn ***list)
{
	**list = tmp;
	while ((**list)->next)
	{
		if (ttmn_in_map(map, **list))
		{
			map = remove_tetriminos(map, **list);
			++(**nb_t);
		}
		**list = (**list)->next;
	}
	if (ttmn_in_map(map, **list))
	{
		map = remove_tetriminos(map, **list);
		++(**nb_t);
	}
	**list = tmp;
	return (map);
}

int			resolve_fillit_2(char **map, int *nb_t, t_ttmn **list, t_ttmn *begin)
{
		t_ttmn 		*save;
		t_ttmn		*tmp;

		tmp = (*list)->prev;
		save = *list;	
		while (nb_t)
		{
			if (search_place(map, *list) && (*nb_t)--)
			{
				*list = begin;
				while ((*list)->next && ttmn_in_map(map, *list))
					*list = (*list)->next;
			}
			else
			{
					
				if ((!(save->next)) && nb_t)
				{	
					map = reset(map, &nb_t, tmp, &list);
					return (0);
				}
				
				*list = tmp;
				map = reset_change_order(map, &nb_t, &save, &list);
			}
		}
		return (1);
}

char		**resolve_fillit(char **map, int nb_t, t_ttmn *list)
{
	int			size_map;
	t_ttmn		*begin;
	int			count;
	t_ttmn		*tmp;

	begin = list;
	size_map = 5;
	count = 0;
	put_max(map, &list, &nb_t);
	while (nb_t)
	{
		if (!ttmn_in_map(map, list) && nb_t)
		{
			map = remove_tetriminos(map, list->prev);
			tmp = list->prev;
			++nb_t;
			if (!(resolve_fillit_2(map, &nb_t, &list, begin)) && nb_t)
			{
				size_map = 6;
			}
			list = tmp;
		}
	}
	return (map);
}
