/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_letters_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:13:20 by liton             #+#    #+#             */
/*   Updated: 2016/12/07 18:51:17 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../Libft/libft.h"

void		ft_add_pos_2(int i, int j, int *k, tt_list *list)
{
	if (list->ttmn[i][j] == '#')
	{
		list->pos[*k][0] = i;
		list->pos[*k][1] = j;
		(*k)++;
	}
}

tt_list		*ft_add_pos(tt_list *list)
{
	tt_list		*begin;
	int			i;
	int			j;
	int			k;

	begin = list;
	i = -1;
	k = 0;
	while (list)
	{
		while (list->ttmn[++i])
		{
			j = -1;
			while (list->ttmn[i][++j])
				ft_add_pos_2(i, j, &k, list);
		}
		list = list->next;
		i = -1;
		k = 0;
	}
	list = begin;
	return (list);
}

tt_list		*ft_add_letters(tt_list *list)
{
	char	alpha;
	tt_list	*begin;

	alpha = 'A';
	begin = list;
	while (list)
	{
		list->letter = alpha;
		alpha++;
		list = list->next;
	}
	list = begin;
	list = ft_add_pos(list);
	return (list);
}
