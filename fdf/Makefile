# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chpark <chpark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 12:37:18 by chpark            #+#    #+#              #
#    Updated: 2022/04/20 12:38:53 by chpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
AFLAGS = rcs

LIBFT 	= libft/libft.a

SRC_D = ./srcs/
SRC 	=	fdf.c \
			map_read.c \
			projection.c \
			draw.c \
			draw_utils.c\
			st_end.c	
OBJ_D := ./obj/
OBJ	= $(SRC:.c=.o)
OBJS := $(addprefix $(OBJ_D), $(OBJ))

HEADERS = headers/fdf.h

MLXLINK = -L minilibx
MINILIBX = -I minilibx
OPENGL = -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(OBJ_D)%.o : $(SRC_D)%.c
	@mkdir -p $(OBJ_D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		make -C minilibx
		make -C libft
		$(CC) $(CFLAG) $(MLXLINK) $(MINILIBX) $(LIBFT) $(OPENGL) $^ -o $(NAME)

clean:
		make clean -C minilibx
		make clean -C libft
		rm -rf $(OBJ_D)

fclean: clean 
		make fclean -C libft
		rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
