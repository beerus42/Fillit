/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 23:47:25 by beerus            #+#    #+#             */
/*   Updated: 2016/11/17 15:21:41 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

char	**reconvert(char *tab)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (4 + 1))))
		return (NULL);
	while (i < 4)
	{
		if (!(new[i] = (char*)malloc(sizeof(char) * (4 + 1))))
			return (NULL);
		j = 0;
		while (j < 4)
		{
			new[i][j] = tab[i];
			j++;
		}
		i++;
		new[i][j] = '\0';
	}
	new[i] = 0;
	return (new);
}

char	*place_tetriminos(char *tmp, char *file, int begin, int lenght)
{
	int		i;

	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * lenght + 1)))
		return (NULL);
	while (i < lenght)
	{
		tmp[i] = file[begin];
		begin++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	**split_str(char **tab, char *file)
{
	int		i;
	int		j;
	int		begin;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = NULL;
	begin = 0;
	while (file[i])
	{
		while (file[i] && (file[i - 1] != '\n' || file[i] != '\n'))
			i++;
		tmp = place_tetriminos(tmp, file, begin, i - begin);
		tab[j] = tmp;
		j++;
		begin = i + 1;
		i++;
	}
	tab[j] = 0;
	return (tab);
}

char	**convert(char *file, int nb_tetriminos)
{
	char	**tab;

	tab = NULL;
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_tetriminos + 1))))
		return (NULL);
	tab = split_str(tab, file);
	return (tab);
}
