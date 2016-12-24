/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_check_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <livbrandon@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 21:23:36 by beerus            #+#    #+#             */
/*   Updated: 2016/12/24 21:42:06 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	 	read_and_check_file(char ***tab, int *nb_t)
{
	char	*buff;
	int		ret;
	int		fd;

	if (!(buff = (char*)malloc(sizeof(char) * 1000)))
			return (0);
	fd = open("sample.fillit", O_RDONLY);
	ret = read(fd, buff, 1000);
	buff[ret] = '\0';
	if (check_file(buff, nb_t))
		*tab = convert(buff, *nb_t);
	else
		return (0);
	if (!check_tetriminos(*tab))
		return (0);
	free(buff);
	return (1);
}
