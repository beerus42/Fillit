/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_to_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:15:29 by liton             #+#    #+#             */
/*   Updated: 2016/12/21 16:21:50 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

void	remove_to_null(char **map, t_ttmn *list)
{
	while (list)
	{
		map = remove_tetriminos(map, list);
		list = list->next;
	}
}
