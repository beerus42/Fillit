/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 03:03:29 by beerus            #+#    #+#             */
/*   Updated: 2016/11/15 15:51:28 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>

typedef struct b_list
{
	int				**pos;
	char			*ttmn;
	char			letter;
	struct 	s_list 	*next;
	struct s_list	*prev;
}				tt_list;
int		check_file_2(char *file, int *i, int *count_wd_pt, int *count_bn);
int		check_file(char *file, int *nb_tetriminos);
char 	*place_tetriminos(char *tmp, char *file, int begin, int lenght);
char	**split(char **tab, char *file);
char	**convert(char *file, int nb_tetriminos);
int		check_tetriminos(char **tab);
void		check_tetriminos_2(char *tab, int j, int *count_ttmn);
#endif
