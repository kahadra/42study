NAME = libftprintf.a
CC = gcc
CFLAGE = -Wall -Werror -Wextra
INCFLAGE = -I./includes
AR = ar crs
RM = rm -rf

SRC = ft_printf_utils.c \
      ft_int_form.c \
      ft_char_form.c \
      ft_put.c \
      ft_itoa.c \
	  ft_printf.c
OBJ_DIR = ./obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

$(NAME) : $(OBJS)
	$(AR) $@ $?
$(OBJ_DIR)%.o : %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGE) $(INCFLAGE) -c $< -o $@
%.o : %.c%

all : $(NAME)
clean :
	$(RM) $(OBJ_DIR)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY : all clean fclean re
