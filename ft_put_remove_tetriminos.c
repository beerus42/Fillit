/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_remove_tetriminos.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:52:21 by liton             #+#    #+#             */
/*   Updated: 2016/12/23 02:06:45 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include "stdlib.h"

int		ttmn_in_map(char **map, t_ttmn *list)
{
	int		i;
	int		j;
	int		size_map;

	size_map = ft_strlen(map[0]);
	i = 0;
	while (i < size_map)
	{
		j = 0;
		while (j < size_map)
		{
			if (map[i][j] == list->letter)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**remove_tetriminos(char **map, t_ttmn *list)
{
	int		i;
	int		j;
	int		size_map;

	size_map = ft_strlen(map[0]);
	i = -1;
	while (++i < size_map)
	{
		j = -1;
		while (++j < size_map)
		{
			if (map[i][j] == list->letter)
				map[i][j] = '.';
		}
	}
	return (map);
}

void	change_y(int y, int y_, int *j)
{
	if (y - y_ > 0)
		++(*j);
	else if (y - y_ == -2)
		*j -= 2;
	else if (y - y_ < 0)
		--(*j);
}

void	change_x(int x, int x_, int *i)
{
	if (x - x_ > 0)
		++(*i);
}

char	**put_tetriminos(char **map, t_ttmn *list, int i, int j)
{
	int			count;
	int			size_map;

	count = 1;
	size_map = ft_strlen(map[0]);
	if (i < size_map && j < size_map && map[i][j] == '.' && count++)
		map[i][j] = list->letter;
	change_x(list->pos[1][0], list->pos[0][0], &i);
	change_y(list->pos[1][1], list->pos[0][1], &j);
	if (i < size_map && j < size_map && map[i][j] == '.' && count++)
		map[i][j] = list->letter;
	change_x(list->pos[2][0], list->pos[1][0], &i);
	change_y(list->pos[2][1], list->pos[1][1], &j);
	if (i < size_map && j < size_map && map[i][j] == '.' && count++)
		map[i][j] = list->letter;
	change_x(list->pos[3][0], list->pos[2][0], &i);
	change_y(list->pos[3][1], list->pos[2][1], &j);
	if (i < size_map && j < size_map && map[i][j] == '.' && count++)
		map[i][j] = list->letter;
	if (count != 5)
		return (remove_tetriminos(map, list));
	return (map);
}
