NAME = philo

CFLAGS  = -Wall -Wextra -Werror -fsanitize=address

CC   = cc

HEADER  = philo.h

RM   = rm -f

SRCS	=	initialization.c philo.c utils.c utils_libft.c \

OBJS   = ${SRCS:.c=.o}

all:   ${NAME}

.c.o:
	${CC} ${CFLAGS} -g -pthread -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)  $(HEADER)
			$(CC) $(OBJS) $(CFLAGS)  -o $(NAME)

clean:
	${RM} ${OBJS} ${OBJS_B}

fclean:  clean
		${RM} ${NAME}

re:   fclean all

.PHONY:  all clean fclean re
