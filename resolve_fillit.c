/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:18:42 by liton             #+#    #+#             */
/*   Updated: 2016/12/24 22:09:44 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

int		resolve_fillit_4(char ***map, int **nb_t, t_ttmn **list, t_ttmn *tmp)
{
	int		size_map;

	size_map = ft_strlen(*map[0]);
	if (**nb_t && search_place(*map, *list) && (**nb_t)--)
	{
		if ((*list)->next)
			*list = (*list)->next;
		else
			return (1);
	}
	else if (!move_right(*map, (*list)->prev, size_map, *nb_t))
	{
		if ((*list)->prev == tmp)
			return (0);
		*list = (*list)->prev;
		while ((*list)->prev != tmp	&& 
		!move_right(*map, (*list)->prev, size_map, *nb_t))
			*list = (*list)->prev;
		if ((*list)->prev == tmp && 
		!move_right(*map, (*list)->prev, size_map, *nb_t))
			return (0);
	}
	return (42);
}

int			resolve_fillit_3(char **map, int *nb_t, t_ttmn *list)
{
	t_ttmn 		*tmp;
	int			bol;

	if (!search_place(map, list))
		return (0);
	--(*nb_t);
	tmp = list;
	if (list->next)
		list = list->next;
	while (*nb_t)
	{
		bol = resolve_fillit_4(&map, &nb_t, &list, tmp);
		if (bol == 0 || bol == 1)
			return (bol);
	}
	return (1);
}


int		resolve_fillit_2(char ***map, int *nb_t, t_ttmn **list, int *size_map)
{
	while (*nb_t && move_right(*map, (*list)->prev, *size_map, nb_t))
	{
		if (resolve_fillit_3(*map, nb_t, *list))
			return (1);
	}
	if (*nb_t && (*list)->prev->letter == 'A')
	{
		free(*map);
		++(*size_map);
		*map = ft_map(*size_map);
		*list = (*list)->prev;
		put_max(*map, list, nb_t);
	}
	else if (!ttmn_in_map(*map, *list) && *nb_t)
		*list = (*list)->prev;
	return (0);
}

char		**resolve_fillit(char **map, int nb_t, t_ttmn *list, int size_map)
{
	t_ttmn	*begin;

	begin = list;
	put_max(map, &list, &nb_t);
	while (nb_t && list == begin)
	{
		++size_map;
		free(map);
		map = ft_map(size_map);
		put_max(map, &list, &nb_t);
	}
	while (nb_t)
	{
		if (resolve_fillit_2(&map, &nb_t, &list, &size_map))
			return (map);
	}
	return (map);
}
