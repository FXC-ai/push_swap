#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*previous;
	struct s_node	*next;
} t_node;

//fct_chained_list_00
t_node	*ft_new_node(int value);
void	ft_destruct_node(t_node *node);
void	ft_display_node(t_node	*node);
void	ft_add_node(t_node **first_node, t_node *new_node);
void	ft_add_node_front(t_node **ptr_first_node, t_node *node);

//fct_chained_list_01
t_node	*ft_last_node(t_node **first_node);
t_node	*ft_create_lst(int *tab, int size_tab);
void	ft_destruct_lst(t_node **first_node);
void	ft_display_lst(t_node **first_node);

//fct_chained_list_02
void	ft_swap(t_node **first_node);
void	ft_rotate(t_node **ptr_first_node);
void	ft_reverse_rotate(t_node **ptr_first_node);

//fct_args_management_00
int		ft_is_number(char *arg);
int		ft_is_int(long nbr);
int		ft_tablen(char **tab);

//fct_args_management_01
int		ft_check_args_int(int argc, long *args);
int		ft_check_args_number(int argc, char **args);
int		ft_check_double(int argc, long *args);

//fct_args_management_02
long	*ft_args_management(int argc, char *argv[], int *args_valid, int *tablen);

#endif