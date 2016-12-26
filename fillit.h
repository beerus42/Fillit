/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 18:36:32 by liton             #+#    #+#             */
/*   Updated: 2016/12/26 18:40:43 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_ttmn
{
	int				pos[4][2];
	int				diez[4][2];
	char			**tab;
	char			letter;
	int				x;
	int				y;
	int				in_map;
	struct s_ttmn	*next;
	struct s_ttmn	*prev;
}				t_ttmn;

int				check_file(char *file, int *nb_tetriminos);
char			**reconvert(char *tab);
char			**convert(char *file, int nb_tetriminos);
int				check_tetriminos(char **tab);
t_ttmn			*in_tab(int nb_t, char **buff);
t_ttmn			*list_ttmn(int nb_t);
t_ttmn			*ft_add_letters(t_ttmn *list);
char			**ft_map(int size);
char			**put_tetriminos(char **map, t_ttmn *list, int i, int j);
char			**remove_tetriminos(char **map, t_ttmn *list);
char			**resolve(char **map, int nb_t, t_ttmn *list, int size_map);
int				ttmn_in_map(char **map, t_ttmn *list);
int				move_right(char **map, t_ttmn *list, int size_map, int *nb_t);
int				search_place(char **map, t_ttmn *list);
int				put_max(char **map, t_ttmn **list, int *nb_t);
int				read_and_check_file(char ***tab, int *nb, char *argv, int ac);
#endif
