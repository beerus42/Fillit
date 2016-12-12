/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 02:54:19 by beerus            #+#    #+#             */
/*   Updated: 2016/12/12 16:16:34 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

#define SHARP new->pos

int    		main(void)
{
	int    		fd;
	int    		ret;
	char   		*buff;
	int    		nb_t;
	char		**tab;
	int			i;
	tt_list		*new;
	int			j;
	int			k;
	char	**map;
	char	**test;

	test = NULL;
	j = 0;
	k = 0;
	ret = 0;
	nb_t = 0;
	i = 0;
	if(!(buff = (char*)malloc(sizeof(char) * 1000)))
		return (0);
	fd = open("sample.fillit", O_RDONLY);
	ret = read(fd, buff, 1000);
	buff[ret] = '\0';
	if (check_file(buff, &nb_t))
		ft_putendl("1");
	else
		ft_putendl("0");
	tab = convert(buff, nb_t);
	if (check_tetriminos(tab))
		printf("1\n");
	else
		printf("0\n");
	if (close(fd) == -1)
		printf("close failed\n");
	new = in_ttmn(nb_t, tab);
	new = ft_add_letters(new);
	map = ft_map(4);
	map = resolve_fillit(map, nb_t, new);
	ft_display_tab(map);
	free(tab);
	return (0);
}
