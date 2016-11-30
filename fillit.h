/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 03:03:29 by beerus            #+#    #+#             */
/*   Updated: 2016/11/30 16:07:49 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>

typedef struct 	b_list
{
	int				pos[4][2];
	char			**ttmn;
	char			letter;
	struct 	b_list 	*next;
	struct b_list	*prev;
}				tt_list;

int			check_file_2(char *file, int *i, int *count_wd_pt, int *count_bn);
int			check_file(char *file, int *nb_tetriminos);
char 		*place_tetriminos(char *tmp, char *file, int begin, int lenght);
char		**split(char **tab, char *file);
char		**convert(char *file, int nb_tetriminos);
int			check_tetriminos(char **tab);
void		check_tetriminos_2(char *tab, int j, int *count_ttmn);
char		**reconvert(char *tab);
tt_list		*in_ttmn(int nb_t, char **buff);
tt_list		*add_right(tt_list *list);
tt_list		*list_ttmn(int nb_t);
tt_list		*ft_add_letters(tt_list *list);
#endif
