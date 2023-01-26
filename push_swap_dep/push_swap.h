#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
    int             ind;
	struct s_node	*previous;
	struct s_node	*next;
} t_node;

//fct_chained_list_ind
t_node	*ft_new_node(int value);
void	ft_destruct_node(t_node *node);
t_node	*ft_last_node(t_node **ptr_first_node);
void	ft_add_node(t_node **ptr_first_node, t_node *new_node);
void	ft_add_node_front(t_node **ptr_first_node, t_node *node);

void	ft_display_node(t_node	*node);
void	ft_display_lst(t_node **first_node);
t_node	*ft_create_lst(int *tab, int size_tab);
void	ft_destruct_lst(t_node **ptr_first_node);

void	ft_swap_a(t_node **ptr_first_node);
void	ft_swap_b(t_node **ptr_first_node);
void	ft_rotate_a(t_node **ptr_first_node);
void	ft_reverse_rotate(t_node **ptr_first_node);
int		ft_stack_is_empty(t_node **ptr_first_node);
t_node	*ft_lst_del_last(t_node **ptr_first_node);

void	ft_push_b(t_node **ptr_first_node_a, t_node **ptr_first_node_b);
void	ft_push_a(t_node **ptr_first_node_a, t_node **ptr_first_node_b);
int		ft_sort_check(t_node **ptr_first_node);
int		ft_size_lst(t_node **ptr_first_node);
int		ft_maxvalue_lst(t_node **ptr_first_node);

int		ft_minvalue_lst(t_node **ptr_first_node);
void    ft_index_lst(t_node **ptr_first_node);
void    ft_sort_two_nodes(t_node **ptr_first_node);
void    ft_sort_three_nodes(t_node **ptr_first_node_a);

void    ft_sort_four_nodes(t_node **ptr_first_node_a, t_node **ptr_first_node_b);
void    ft_sort_five_nodes(t_node **ptr_first_node_a, t_node **ptr_first_node_b);


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