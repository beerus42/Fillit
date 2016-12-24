/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_remove_tetriminos.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:52:21 by liton             #+#    #+#             */
/*   Updated: 2016/12/24 21:03:28 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

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
