/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 02:54:19 by beerus            #+#    #+#             */
/*   Updated: 2016/12/26 18:43:48 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include "fillit.h"

int		main(int ac, char **av)
{
	t_ttmn		*new;
	int			nb_t;
	char		**tab;
	char		**map;

	nb_t = 1;
	new = NULL;
	tab = NULL;
	if (!read_and_check_file(&tab, &nb_t, av[1], ac) || nb_t <= 0 || nb_t > 26)
		ft_putendl("error");
	else
	{
		new = in_tab(nb_t, tab);
		new = ft_add_letters(new);
		map = ft_map(2);
		map = resolve(map, nb_t, new, 2);
		ft_display_tab(map);
		free(tab);
		free(map);
	}
	return (0);
}
