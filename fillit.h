/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 03:03:29 by beerus            #+#    #+#             */
/*   Updated: 2016/11/09 17:54:55 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>
int		check_file_2(char *file, int *i, int *count_wd_pt, int *count_bn);
int		check_file(char *file, int *nb_tetriminos);
char 	*place_tetriminos(char *tmp, char *file, int begin, int lenght);
char	**split(char **tab, char *file);
char	**convert(char *file, int nb_tetriminos);
int		check_tetriminos(char **tab);
void		check_tetriminos_2(char *tab, int j, int *count_ttmn);
#endif
