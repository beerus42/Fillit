/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 20:58:43 by beerus            #+#    #+#             */
/*   Updated: 2016/10/25 23:33:15 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

int		check_tetriminos_2(char *tab, int j)
{
	if (tab[j - 1] && tab[j - 1] == 35)
    	return (1);
	if (tab[j + 1] && tab[j + 1] == 35)	
		return (1);
  	if (tab[j - 5] && tab[j - 5] == 35)
    	return (1);
  	if (tab[j + 5] && tab[j + 5] == 35)
    	return (1);
  	return (0);
}

int		check_tetriminos(char **tab)
{
	int		i;
	int		j;
	int		count_wd;

	i = -1;
	j = -1;
	count_wd = 0;
	while (tab[++i])
	{
		while (tab[i][++j])
		{
			if (tab[i][j] == '#')
			{
				++count_wd;
				if (check_tetriminos_2(tab[i], j) == 0)
					return (0);
			}
		}
		if (count_wd != 4)
			return (0);
		count_wd = 0;
		j = -1;
	}
	return (1);
}

int		check_file_2(char *file, int *i, int *count_wd_pt, int *count_bn)
{
	if (file[*i] == '#' || file[*i] == '.')
		(*count_wd_pt)++;
	if (file[*i] == '\n')
	{
		if (*count_wd_pt != 4)
			return (0);
		*count_wd_pt = 0;
		(*count_bn)++;
	}
	if (file[*i] == '\n' && file[(*i) + 1] == '\n')
	{
		if (*count_bn != 5)
			return (0);
		*count_bn = 0;
		(*i)++;
	}
	return (1);
}

int		check_file(char *file, int *nb_tetriminos)
{
	int		i;
	int		count_wd_pt;
	int		count_bn;

	i = -1;
	count_wd_pt = 0;
	count_bn = 0;
	while (file[++i])
	{
		if (file[i] == '\n' && file[i + 1] == '\n')
			(*nb_tetriminos)++;
		if (check_file_2(file, &i, &count_wd_pt, &count_bn) == 0)
			return (0);
	}
	if (file[i - 1] == '\n' && file[i - 2] == '\n')
		return (0);
	return (1);
}
