# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daleksan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 19:23:14 by daleksan          #+#    #+#              #
#    Updated: 2017/10/29 14:53:29 by daleksan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc

FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -lmlx -framework OpenGL -framework AppKit

NAME = wolf3d

SRC = wolf.c redraw_wolf.c read_map.c read_sprites.c init.c hooks.c txt_col_man.c\
		draw_lines.c sprite_cast.c sprite_cast_2.c

LIB = libft/libft.a
LIBPRINT = ft_printf/libftprintf.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C ft_printf/
	$(CC) $(FLAGS) $(FLAGS_MLX) $(OBJ) $(LIB) $(LIBPRINT) -o $(NAME)
	@echo "\033[32;1m<<wolf3d done>>\033[0m"

%.o: %.c
	@gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	@rm -f $(OBJ)
	@echo "\033[31m<<Deleted objects>>\033[31m"
	
fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@rm -rf $(NAME)
	@echo "\033[31m<<Deleted wolf3d>>\033[31m"

re: clean all
