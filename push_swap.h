#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	struct s_node	*previous;
	struct s_node	*next;
} t_node;

t_node	*ft_new_node(int value);
void	ft_destruct_node(t_node *node);
void	ft_display_node(t_node	*node);
t_node	*ft_last_node(t_node **first_node);
void	ft_add_node(t_node **first_node, t_node *new_node);
t_node	*ft_create_lst(int *tab, int size_tab);
void	ft_destruct_lst(t_node **first_node);
void	ft_display_lst(t_node **first_node);
void	ft_swap(t_node **first_node);
void	ft_rotate(t_node **ptr_first_node);
void	ft_reverse_rotate(t_node **ptr_first_node);



#endif