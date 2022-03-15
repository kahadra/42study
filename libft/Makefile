NAME := libft.a

SRC1 := ft_atoi.c \
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_tolower.c\
		ft_toupper.c
SRC2 := ft_substr.c\
		ft_strmapi.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_itoa.c\
		ft_split.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c

BONUS := ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstadd_back.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c


OBJ_N1 := $(SRC1:.c=.o)
OBJ_N2 := $(SRC2:.c=.o)
OBJ_B := $(BONUS:.c=.o)
OBJ_D := ./obj/
OBJ := $(addprefix $(OBJ_D), $(OBJ_N1)) $(addprefix $(OBJ_D), $(OBJ_N2))
OBJ_BO := $(addprefix $(OBJ_D), $(OBJ_B))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
AFLAGS = rcs

all : $(NAME)

clean :
	rm -rf $(OBJ_D)
fclean : clean
	rm -f $(NAME)
bonus : $(OBJ_BO)
	$(AR) $(AFLAGS) $(NAME) $?

re : fclean all

$(NAME) : $(OBJ)
	$(AR) $(AFLAGS) $@ $?
$(OBJ_D)%.o : %.c
	@mkdir -p $(OBJ_D)
	$(CC) $(CFLAGS) -c $< -o $@
%.o : %.c%
.PHONY : all clean fclean bonus re
