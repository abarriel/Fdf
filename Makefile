# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 15:43:55 by abarriel          #+#    #+#              #
#    Updated: 2017/01/26 15:30:30 by abarriel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC		=	fdf.c get.c tab.c trace.c add.c

OBJ		= $(addprefix src/,$(SRC:.c=.o))

CFLAGS	=  -Iincludes/ -Ilibft/includes/

$(NAME): $(OBJ)
	@make -C libft
	@gcc -lmlx -framework OpenGL -framework Appkit $(OBJ) -o $(NAME) -L libft/ -lft -Ilibft/includes/

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make -C libft/ fclean

re: fclean $(NAME)
