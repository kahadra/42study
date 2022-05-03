# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
<<<<<<< HEAD
#    By: wonkim <wonkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 17:50:22 by wonkim            #+#    #+#              #
#    Updated: 2022/04/24 22:05:55 by wonkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
BONUS_NAME		= 	fdf_bonus

LIB_DIR			= ./LIBS
MLX_DIR			= $(LIB_DIR)/MLX

SRCS 			=	SRCS/00_main.c\
					SRCS/01_check.c\
					SRCS/02_init.c\
					SRCS/03_parse.c\
					SRCS/04_parse_utils.c\
					SRCS/05_draw.c\
					SRCS/06_draw_utils.c\
					SRCS/07_key_hook.c\
					SRCS/08_utils1.c\
					SRCS/09_utils2.c\
					SRCS/10_utils3.c\
					LIBS/GNL/get_next_line.c\
					LIBS/GNL/get_next_line_utils.c\

OBJ				= $(SRCS:.c=.o)

CC				= gcc
RM				= rm
CFLAGS			= -Wall -Wextra -Werror -g
MLX_FLAGS		= -L./LIBS/MLX -lmlx -framework OpenGL -framework Appkit
RMFLAGS			= -f

all:			$(NAME)

$(NAME):		$(OBJ)
				make -C $(MLX_DIR)
				$(CC) ${CFLAGS} $(MLX_FLAGS) $^ -o $@

$(BONUS_NAME):	$(OBJ)
				make -C $(MLX_DIR)
				$(CC) ${CFLAGS} $(MLX_FLAGS) $^ -o ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
				$(RM) $(RMFLAGS) $(OBJ)

fclean:			clean
				$(RM) $(RMFLAGS) $(NAME)
				$(RM) $(RMFLAGS) $(BONUS_NAME)

re:				fclean all

bonus :			$(BONUS_NAME)

.PHONY:			all clean fclean re
=======
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
>>>>>>> 3e11605bb0d6cfe155e4c275ad71df6aee645ecd
