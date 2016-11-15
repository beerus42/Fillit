/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 20:58:43 by beerus            #+#    #+#             */
/*   Updated: 2016/11/15 15:49:16 by liton            ###   ########.fr       */
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

int			check_file_2(char *file, int *i, int *count_wd_pt, int *count_bn)
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
		if (*count_bn != 4)
			return (0);
		*count_bn = 0;
		(*i)++;
	}
	return (1);
}

int			check_file(char *file, int *nb_tetriminos)
{
	int		i;
	int		count_wd_pt;
	int		count_bn;

	i = -1;
	count_wd_pt = 0;
	count_bn = 0;
	if (!file)
		return (0);
	while (file[++i])
	{
		if (file[i + 1] && file[i] == '\n' && file[i + 1] == '\n')
			(*nb_tetriminos)++;
		if (check_file_2(file, &i, &count_wd_pt, &count_bn) == 0)
			return (0);
	}
	if (file[i - 1] != '\n' || file[i - 2] != '\n')
		return (0);
	return (1);
}
