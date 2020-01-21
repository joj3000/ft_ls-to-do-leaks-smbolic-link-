# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerbs <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/25 17:54:30 by jerbs             #+#    #+#              #
#    Updated: 2020/01/21 09:33:00 by jerbs            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wall -Werror -Wextra
.C = *.c
.O = *.o

$(NAME):
	gcc $(FLAGS) -c $(.C)
	gcc -o $(NAME) $(.O)

all:	$(NAME)

clean:
	rm -rf $(.O)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: clean fclean re all
