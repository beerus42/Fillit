/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_letters_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:13:20 by liton             #+#    #+#             */
/*   Updated: 2016/12/24 21:01:26 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

void		check_tetriminos_2(char *tab, int j, int *count_ttmn)
{
	if (tab[j + 1] && tab[j + 1] == 35)
		(*count_ttmn)++;
	if (tab[j + 5] && tab[j + 5] == 35)
		(*count_ttmn)++;
}

int			check_tetriminos(char **tab)
{
	int		i;
	int		j;
	int		count_wd;
	int		count_ttmn;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		count_wd = 1;
		count_ttmn = 0;
		while (tab[i][++j])
		{
			if (tab[i][j] == '#' && count_wd++)
				check_tetriminos_2(tab[i], j, &count_ttmn);
		}
		if (count_wd != 5 || (count_ttmn != 3 && count_ttmn != 4))
			return (0);
	}
	return (1);
}
