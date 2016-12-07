/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_fillit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:52:21 by liton             #+#    #+#             */
/*   Updated: 2016/12/07 18:37:45 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

char	**put_tetriminos(char **map, tt_list *list)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (count != 4)
	{
		if (map[i][j] == '.')
		{
			map[i][j] = list->letter;
			count++;
		}
		i++;
	}
	return (map);
}
