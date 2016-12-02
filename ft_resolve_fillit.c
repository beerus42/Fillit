/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_fillit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:52:21 by liton             #+#    #+#             */
/*   Updated: 2016/12/02 18:00:16 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

char		**put_tetriminos(tt_list *list, char **map, int i, int j)
{
	int		good;
	int		i;
	int		j;

	good = 1;
	i = 0;
	j = 0;
	while (good)
	{
		map[i][j] = new->ttmn[pos[0][0]][pos[0][1]];
	}
}

char		**resolve_fillit(tt_list *list, char **map)
{
	tt_list 	*begin
	int			i;
	int			j;

	begin = list;
	i = 0;
	j = 0;
	while (list)
	{
		if (map[i][j] && map[i][j] == '.')
		{
		
		}
	}
}
