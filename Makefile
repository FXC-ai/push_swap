HEADIR  = includes

SRCS 	= args_management.c fct_chained_lst.c main.c

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I${HEADIR}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C libft
			$(CC) $^ -Llibft -lft -o $(NAME)


all:		${NAME}

clean:		
			make clean -C ft_printf
			${RM} ${OBJS}

fclean:		clean
			make fclean -C ft_printf
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re