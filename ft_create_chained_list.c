/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_tt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:11:45 by liton             #+#    #+#             */
/*   Updated: 2016/12/24 21:01:55 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

t_ttmn		*in_ttmn(int nb_t, char **buff)
{
	int		i;
	t_ttmn	*new;
	t_ttmn	*begin;

	i = 0;
	new = list_ttmn(nb_t);
	begin = new;
	while (buff[i])
	{
		new->tab = reconvert(buff[i]);
		++i;
		new = new->next;
	}
	new = begin;
	return (new);
}

t_ttmn		*add_right(t_ttmn *list)
{
	t_ttmn 		*new;
	t_ttmn		*begin;

	begin = list;
	if (!(new = (t_ttmn*)malloc(sizeof(t_ttmn))))
		return (NULL);
	while (list->next)
		list = list->next;
	list->next = new;
	new->next = NULL;
	new->prev = list;
	list = begin;
	return (list);
}

t_ttmn		*list_ttmn(int nb_t)
{
	t_ttmn		*new;
	t_ttmn		*begin;
	int			i;

	i = 1;
	if (!(new = (t_ttmn*)malloc(sizeof(t_ttmn))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	begin = new;
	while (i < nb_t)
	{
		new = add_right(new);
		new = new->next;
		++i;
	}
	new = begin;
	return (new);
}
