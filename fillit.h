/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 03:03:29 by beerus            #+#    #+#             */
/*   Updated: 2016/12/13 19:44:53 by liton            ###   ########.fr       */
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
	int				in_map;
	int				x;
	int				y;
	struct 	b_list 	*next;
	struct b_list	*prev;
}				tt_list;

int			check_file(char *file, int *nb_tetriminos);
char		**convert(char *file, int nb_tetriminos);
char		**reconvert(char *tab);	
int			check_tetriminos(char **tab);
tt_list		*in_ttmn(int nb_t, char **buff);
tt_list		*list_ttmn(int nb_t);
tt_list		*ft_add_letters(tt_list *list);
char		**ft_map(int size);
char		**put_tetriminos(char **map, tt_list *list, int i, int j);
char		**remove_tetriminos(char **map, tt_list *list);
char		**resolve_fillit(char **map, int nb_t, tt_list *list);
int			ttmn_in_map(char **map, tt_list *list);
#endif
