/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_letters_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:13:20 by liton             #+#    #+#             */
/*   Updated: 2016/12/25 05:22:49 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../Libft/libft.h"

void		ft_add_pos_2(int i, int j, int *k, t_ttmn *list)
{
	if (list->tab[i][j] == '#')
	{
		list->pos[*k][0] = i;
		list->pos[*k][1] = j;
		++(*k);
	}
}

t_ttmn		*ft_add_pos(t_ttmn *list, t_ttmn *begin)
{
	int			i;
	int			j;
	int			k;

	list = begin;
	i = -1;
	k = 0;
	while (list)
	{
		while (list->tab[++i])
		{
			j = -1;
			while (list->tab[i][++j])
				ft_add_pos_2(i, j, &k, list);
		}
		list = list->next;
		i = -1;
		k = 0;
	}
	list = begin;
	return (list);
}

t_ttmn		*ft_add_letters(t_ttmn *list)
{
	char		alpha;
	int			n;
	t_ttmn		*begin;

	alpha = 'A';
	n = 1;
	begin = list;
	while (list)
	{
		list->letter = alpha;
		++alpha;
		list = list->next;
	}
	list = ft_add_pos(list, begin);
	return (list);
}
