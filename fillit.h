/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 03:03:29 by beerus            #+#    #+#             */
/*   Updated: 2016/10/25 02:49:16 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

int		check_file_2(char *file, int *i, int *count_wd_pt, int *count_bn);
int		check_file(char *file, int *nb_tetriminos);
char 	*place_tetriminos(char *tmp, char *file, int begin, int lenght);
char	**split(char **tab, char *file);
char	**convert(char *file, int nb_tetriminos);
int		check_tetriminos(char **tab);
int		check_tetriminos_2(char *tab, int j);
#endif
