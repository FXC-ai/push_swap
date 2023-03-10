HEADIR  = includes

SRCS 	= fct_algo_launcher.c fct_sort_big.c fct_sort_five.c fct_sort_four.c fct_sort_three.c fct_sort_tools.c args_management_00.c args_management_01.c args_management_02.c fct_big_sort_tools.c fct_chained_lst_00.c fct_chained_lst_01.c fct_action_lst_00.c fct_action_lst_01.c main.c

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
			make clean -C libft
			${RM} ${OBJS}

fclean:		clean
			make fclean -C libft
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re