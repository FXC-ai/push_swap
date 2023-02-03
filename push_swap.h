/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:37:58 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/03 14:53:16 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}	t_node;

char	*ft_join_args(int argc, char *argv[]);
char	**ft_create_tab_char(int argc, char *argv[]);
int		ft_size_table(char **tab_char);
int		ft_check_number(char *str);
int		ft_check_args_number(char **tab_char, int tablen);
void	ft_free_tab_char(char **tab, int tablen);
long	*ft_create_tab_long(char **tab_char, int tablen);
int		ft_check_args_int(char **tab_char, long *tab_long, int tablen);
int		ft_check_args_double(char **tab_char, long *tab_long, int tablen);
t_node	*ft_new_node(int value);
t_node	*ft_last_node(t_node **ptr_first_node);
void	ft_add_node(t_node **ptr_first_node, t_node *new_node);
t_node	*ft_create_lst(int *tab, int size_tab);
void	ft_display_node(t_node	*node);
void	ft_display_lst(t_node **first_node, char *name);
void	ft_destruct_node(t_node *node);
void	ft_destruct_lst(t_node **ptr_first_node);
t_node	*ft_lst_del_last(t_node **ptr_first_node);
t_node	*ft_lst_del_first(t_node **ptr_first_node);
void	ft_add_node_front(t_node **ptr_first_node, t_node *node);
int		ft_size_lst(t_node **ptr_first_node);
void	ft_swap_a(t_node **ptr_first_node_a);
void	ft_swap_b(t_node **ptr_first_node_b);
void	ft_rotate_a(t_node **ptr_first_node_a);
void	ft_rotate_b(t_node **ptr_first_node_b);
void	ft_reverse_rotate_a(t_node **ptr_first_node_a);
void	ft_reverse_rotate_b(t_node **ptr_first_node_b);
void	ft_push_b(t_node **ptr_first_node_a, t_node **ptr_first_node_b);
void	ft_push_a(t_node **ptr_first_node_a, t_node **ptr_first_node_b);
int		*ft_convert_longtoint(long *tab_long, int tablen);
int		ft_check_is_sorted(t_node **ptr_first_node);
void	ft_sort_two(t_node **ptr_first_node);
void	ft_sort_three(t_node **ptr_first_node_a);
void	ft_sort_four(t_node **ptr_first_node_a, t_node **ptr_first_node_b);
void	ft_sort_five(t_node **ptr_first_node_a, t_node **ptr_first_node_b);
void	ft_sort_int_tab(int *tab, int size);
void	ft_set_index_lst(t_node **ptr_first_node, int *tab_int, int tablen);
int		ft_find_max_chunk(int size_stack, int nb_chunk, int id_chunk);
int		ft_find_min_chunk(int size_stack, int nb_chunk, int id_chunk);
int		ft_srch_from_bottom_a(t_node **ptr_first_nod, int ind_min, int ind_max);
int		ft_srch_from_top_a(t_node **ptr_first_node, int ind_min, int ind_max);
int		ft_srch_from_bottom_b(t_node **ptr_first_node, int ind_value);
int		ft_srch_from_top_b(t_node **ptr_first_node, int ind_value);
int		ft_calculate_nb_chunk(int tablen);
void	ft_cor_al2(t_node **ptr_first_node_a, t_node **ptr_first_node_b, int i);
void	ft_st2(t_node **ptr_first_node_a, t_node **ptr_first_node_b, int tabln);
void	ft_cor_al1(t_node **ptr_frst_a, t_node **ptr_first_b, int min, int max);
void	ft_st1(t_node **ptr_first_a, t_node **ptr_first_b, int min, int max);
void	ft_st(t_node **ptr_first_node_a, t_node **ptr_first_node_b, int tablen);
void	ft_choose_algo(t_node **ptr_first_a, t_node **ptr_first_b, int tablen);
int		ft_launch_algo(int *tab_int, int tablen);
int		ft_check_int_double(char **tab_char, long *tab_long, int tablen);

#endif