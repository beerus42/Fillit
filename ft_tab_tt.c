/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_tt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:11:45 by liton             #+#    #+#             */
/*   Updated: 2016/11/15 17:49:53 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

tt_list		*add_righ(tt_list *list)
{
	tt_list *new;
	tt_list *begin;

	begin = list;
	if (!(new = (tt_list*)malloc(sizeof(tt_list))))
		return (NULL);
	while (list->next)
		list = list->next;
	list->next = new;
	new->next = NULL;
	list = begin;
	return (list);
}

tt_list		*reconvert(char **tab, int *nb_t)
{
	tt_list 	*new;
	tt_list 	*begin;
	int			i;

	i = 1;
	if(!(new = (tt_list*)malloc(sizeof(tt_list))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	begin = new;
	while (i <= *nb_t)
	{
		new = new->next;
	}
}
