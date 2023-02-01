#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	int				ind;
	struct s_node	*previous;
	struct s_node	*next;
} t_node;

//fct_args_management
int		ft_check_number(char *str);
int		ft_check_args_number(char **tab_char, int tablen);
char    *ft_join_args(int argc, char *argv[]);
void	ft_free_tab_char(char **tab, int tablen);
int		ft_size_table(char **tab_char);
long 	*ft_create_tab_long(char **tab_char, int tablen);
int		ft_check_args_int(long *tab_long, int tablen);
int		ft_check_args_double(long *tab_long, int tablen);


//fct_chained_lst
t_node	*ft_new_node(int value);
t_node	*ft_last_node(t_node **ptr_first_node);
void	ft_add_node(t_node **ptr_first_node, t_node *new_node);
t_node	*ft_create_lst(int *tab, int size_tab);
void	ft_display_node(t_node	*node);
void	ft_display_lst(t_node **first_node, char *name);
void	ft_destruct_node(t_node *node);
void	ft_destruct_lst(t_node **ptr_first_node);
t_node    *ft_lst_del_last(t_node **ptr_first_node);
t_node  *ft_lst_del_first(t_node **ptr_first_node);
void	ft_add_node_front(t_node **ptr_first_node, t_node *node);
int ft_size_lst(t_node **ptr_first_node);
void	ft_swap_a(t_node **ptr_first_node_a);
void	ft_swap_b(t_node **ptr_first_node_b);
void	ft_rotate_a(t_node **ptr_first_node_a);
void	ft_rotate_b(t_node **ptr_first_node_b);
void	ft_reverse_rotate_a(t_node **ptr_first_node_a);
void	ft_reverse_rotate_b(t_node **ptr_first_node_b);
void ft_push_b(t_node **ptr_first_node_a, t_node **ptr_first_node_b);
void ft_push_a(t_node **ptr_first_node_a, t_node **ptr_first_node_b);
int *ft_convert_longtoint(long *tab_long, int tablen);
int ft_check_is_sorted(t_node **ptr_first_node);
void    ft_sort_two(t_node **ptr_first_node);
void    ft_sort_three(t_node **ptr_first_node_a);
void    ft_sort_four(t_node **ptr_first_node_a, t_node **ptr_first_node_b);


#endif