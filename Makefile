HEADIR  = includes

SRCS 	= fct_args_management_00.c fct_args_management_01.c fct_args_management_02.c fct_chained_list_00.c fct_chained_list_01.c fct_chained_list_02.c main.c

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I${HEADIR}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ft_printf
			$(CC) $^ -Lft_printf -lftprintf -o $(NAME)


all:		${NAME}

clean:		
			make clean -C ft_printf
			${RM} ${OBJS}

fclean:		clean
			make fclean -C ft_printf
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re