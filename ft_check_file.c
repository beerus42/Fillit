/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 20:58:43 by beerus            #+#    #+#             */
/*   Updated: 2016/12/24 20:59:49 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

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
