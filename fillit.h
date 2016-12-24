/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 03:03:29 by beerus            #+#    #+#             */
/*   Updated: 2016/12/24 21:38:41 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>

#define RR ft_display_tab(map)

typedef struct 	b_list
{
	int				pos[4][2];
	int				diez[4][2];
	char			**tab;
	char			letter;
	int				x;
	int				y;
	int				in_map;
	struct 	b_list 	*next;
	struct b_list	*prev;
}				t_ttmn;

int			check_file(char *file, int *nb_tetriminos);
char		**convert(char *file, int nb_tetriminos);
char		**reconvert(char *tab);	
int			check_tetriminos(char **tab);
t_ttmn		*in_ttmn(int nb_t, char **buff);
t_ttmn		*list_ttmn(int nb_t);
t_ttmn		*ft_add_letters(t_ttmn *list);
char		**ft_map(int size);
char		**put_tetriminos(char **map, t_ttmn *list, int i, int j);
char		**remove_tetriminos(char **map, t_ttmn *list);
char		**resolve_fillit(char **map, int nb_t, t_ttmn *list, int size_map);
int			ttmn_in_map(char **map, t_ttmn *list);
int			move_right(char **map, t_ttmn *list, int size_map, int *nb_t);
int			search_place(char **map, t_ttmn *list);	
int			put_max(char **map, t_ttmn **list, int *nb_t);
int			read_and_check_file(char ***tab, int *nb);
#endif
