#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: beerus <bckeur@free.exe>                   +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/10/06 23:08:58 by beerus            #+#    #+#             *#
#*   Updated: 2016/12/08 04:38:19 by beerus           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fillit

NAME_H = fillit.a

SRC_NAME = ft_check_file.c 		 			\
		   ft_convert.c	   		 			\
		   ft_tab_tt.c			 			\
		   ft_add_letters_pos.c     		\
		   ft_map.c				    		\
		   ft_put_remove_tetriminos.c 		\
		   ft_main.c

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
