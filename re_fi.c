/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_fi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <livbrandon@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 21:37:04 by beerus            #+#    #+#             */
/*   Updated: 2016/12/20 22:50:36 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		resolve_fillit_2(char **map, int *nb_t, t_ttmn *list)
{
	if (!search_place(map, list))
		return (0);
	--(*nb_t);
	if (list->next)
		list = list->next;
	while(*nb_t && move_right(map, list->prev))
	{
		if (*nb_t && search_place(map, list) && (*nb_t)--)
		{
			if (list->next)
				list->next;
			else
				return (1);
		}
	}
	return (0);
}
