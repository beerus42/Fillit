/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_remove_tetriminos.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:52:21 by liton             #+#    #+#             */
/*   Updated: 2016/12/08 04:39:58 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include "stdlib.h"

char	**remove_tetriminos(char **map, tt_list *list)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == list->letter)
				map[i][j] = '.';
		}
	}
	return (map);
}

char	**ft_strcpyy(char **tab, char **map)
{
	int		i;
	int		j;

	i = -1;
	if (!(tab = (char**)malloc(sizeof(char*) * ft_strlen(map[0]) + 1)))
		return (NULL);
	while (map[++i])
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * ft_strlen(map[0] + 1))))
			return (NULL);
		j = -1;
		while (map[i][++j])
			tab[i][j] = map[i][j];
	}
	tab[i] = 0;
	return (tab);
}

void	change_y(int y, int y_, int *j)
{
	if (y - y_ > 0)
		++(*j);
	else if (y - y_ < 0)
		--(*j);
}

void	change_x(int x, int x_, int *i)
{
	if (x - x_ > 0)
		++(*i);
}

char	**put_tetriminos(char **map, tt_list *list, int i, int j)
{
	int			count;
	char	**map_cpy;

	count = 1;
	map_cpy = NULL;
	map_cpy = ft_strcpyy(map_cpy, map);
	if (map[i] && map[i][j] && map[i][j] == '.' && count++)
		map[i][j] = list->letter;
	change_x(list->pos[1][0], list->pos[0][0], &i);
	change_y(list->pos[1][1], list->pos[0][1], &j);
	if (map[i] && map[i][j] && map[i][j] == '.' && count++)
		map[i][j] = list->letter;
	change_x(list->pos[2][0], list->pos[1][0], &i);
	change_y(list->pos[2][1], list->pos[1][1], &j);
	if (map[i] && map[i][j] && map[i][j] == '.' && count++)
		map[i][j] = list->letter;
	change_x(list->pos[3][0], list->pos[2][0], &i);
	change_y(list->pos[3][1], list->pos[2][1], &j);
	if (map[i] && map[i][j] && map[i][j] == '.' && count++)
		map[i][j] = list->letter;
	if (count != 5)
		return (map_cpy);
	return (map);
}
