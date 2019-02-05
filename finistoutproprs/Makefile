# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutricot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 15:13:34 by hutricot          #+#    #+#              #
#    Updated: 2019/02/05 14:45:15 by hutricot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FILE = map_test/42.fdf

FLAGS = -Wall -Wextra -Werror

SRC = \
	main.c \
	ft_error.c \
	ft_window.c \
	line_draw2.c \
	ft_display.c \
	ft_swap.c \
	ft_iso.c \
	  
OBJ = $(SRC:.c=.o)

INC = h.h


all: $(NAME)

$(NAME) : $(INC) $(OBJ) $(SRC)
	make -C libft
	gcc $(FLAGS) -c $(SRC) -I$(INC)
	gcc $(FLAGS) -o $(NAME) libft/libft.a $(OBJ) -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit 

test : all
	./$(NAME) $(FILE)

clean :
	rm -f $(OBJ)
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	rm -f libft/libft.a

re : fclean all

