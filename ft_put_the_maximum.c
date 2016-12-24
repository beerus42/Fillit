/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:18:42 by liton             #+#    #+#             */
/*   Updated: 2016/12/24 21:16:38 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

int			put_max(char **map, t_ttmn **list, int *nb_t)
{
	while ((*list)->next && !ttmn_in_map(map, *list) && *nb_t)
	{
		if (*nb_t && !search_place(map, *list))
			return (0);
		*list = (*list)->next;
		--(*nb_t);
	}
	if (!search_place(map, *list))
		return (0);
	--(*nb_t);
	return (1);
}
