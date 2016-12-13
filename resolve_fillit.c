/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:18:42 by liton             #+#    #+#             */
/*   Updated: 2016/12/13 19:40:02 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

char	**resolve_fillit(char **map, int nb_t, tt_list *list)
{
	int			i;
	int			j;
	int			size_map;
	int			count;
	tt_list		*begin;
	tt_list		*tmp;
	tt_list		*debug;

	begin = list;
	count = 0;
	size_map = 5;
	debug = list->next->next->next->next;
	while (count != nb_t)
	{
		if (!ttmn_in_map(map, list))
		{
			i = 0;
			while (map[i] && count != nb_t)
			{
				j = 0;
				while (map[i][j] && count != nb_t)
				{
					ft_display_tab(map);
					ft_putchar('\n');
					if (map[i] && map[i][j] && map[i][j] == '.')
					{
						if (!ttmn_in_map(map, list))
							map = put_tetriminos(map, list, i, j);
						if (ttmn_in_map(map, list))
						{
							list->in_map = 1;
							list = begin;
							while (list->next && list->in_map)
								list = list->next;
							++count;
						}
					}
					++j;
				}
				++i;
			}
			if (!list->in_map)
			{
				if (list->next)
				{
				printf("BLALALALA = [[[%c]]]]\n", list->letter);
			//	printf("BLABLA = [[%i]]\n", list->next->in_map);
					while (list->next && list->in_map)
					{
//				printf("[[[%c]]]]\n", list->letter);
						list = list->next;
					}
				}
				else
				{
					tmp = list;
					while (list->prev && !list->in_map)
						list = list->prev;
					map = remove_tetriminos(map, list);
					list->in_map = 0;
					list = tmp;
					--count;
				}
			}
		}
	}
	return (map);
}
