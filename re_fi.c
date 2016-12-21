/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_fi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <livbrandon@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 21:37:04 by beerus            #+#    #+#             */
/*   Updated: 2016/12/21 04:02:15 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		resolve_fillit_2(char **map, int *nb_t, t_ttmn *list)
{
	t_ttmn 	*tmp

	if (!search_place(map, list))
		return (0);
	--(*nb_t);
	tmp = list;
	if (list->next)
		list = list->next;
	while(*nb_t)
	{
		if (*nb_t && search_place(map, list) && (*nb_t)--)
		{
			if (list->next)
				list->next;
			else
				return (1);
		}
		else if ((!move_right(map, list->prev)) && list->prev != tmp)
			list = list->prev;
		else if (!move_right(map, list->prev))
			return (0);
	}
	return (1);
}
