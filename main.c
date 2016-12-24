/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 02:54:19 by beerus            #+#    #+#             */
/*   Updated: 2016/12/24 21:42:55 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include "fillit.h"

int    		main(void)
{
	int    		nb_t;
	t_ttmn		*new;
	char	**tab;
	char	**map;

	nb_t = 0;
	new = NULL;
	tab = NULL;
	if (!read_and_check_file(&tab, &nb_t))
		printf("error\n");
	else
	{
		new = in_ttmn(nb_t, tab);
		new = ft_add_letters(new);
		map = ft_map(2);
		map = resolve_fillit(map, nb_t, new, 2);
		ft_display_tab(map);
		free(tab);
	}
	return (0);
}
