#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/10/06 23:08:58 by beerus            #+#    #+#             *#
#*   Updated: 2016/12/24 21:37:18 by beerus           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fillit

NAME_H = fillit.a

SRC_NAME = ft_check_file.c 		 			\
		   ft_convert.c	   		 			\
		   ft_create_chained_list.c			\
		   ft_add_letters_pos.c     		\
		   ft_map.c				    		\
		   ft_put_tetriminos.c 		        \
		   ft_check_tetriminos.c            \
		   resolve_fillit.c					\
		   ft_tetriminos_in_map.c           \
		   ft_remove_tetriminos.c           \
		   ft_move_right.c                  \
		   ft_search_place.c	            \
		   ft_put_the_maximum.c             \
		   ft_read_check_file.c             \
		   main.c

OBJ_NAME = $(SRC_NAME:.c=.o)

all:
	@echo "Conversion des sources en objet"
	@gcc -Wall -Werror -Wextra -c $(SRC_NAME)
	@echo "Link des objets"
	@ar rc $(NAME_H) $(OBJ_NAME)
	@echo "Indexation de la librairie"
	@ranlib $(NAME_H)
	@echo "Compilation des fichiers"
	@gcc -Wall -Werror -Wextra libft.a $(SRC_NAME) $(NAME_H) -o $(NAME)

clean:
	@echo "Supression des objets"
	@rm -rf $(OBJ_NAME)

fclean: clean
	@echo "Supression de l'executable"
	@rm -rf $(NAME)
	@rm -rf $(NAME_H)

re: fclean all
