/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_action_lst_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:47:26 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/03 12:25:08 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_node **ptr_first_node_a)
{
	t_node	*first_node_a;

	if (*ptr_first_node_a != NULL && ft_size_lst(ptr_first_node_a) > 1)
	{
		first_node_a = ft_lst_del_first(ptr_first_node_a);
		ft_add_node(ptr_first_node_a, first_node_a);
		write(1, "rra\n", 4);
	}
}

void	ft_reverse_rotate_b(t_node **ptr_first_node_b)
{
	t_node	*first_node_b;

	if (*ptr_first_node_b != NULL && ft_size_lst(ptr_first_node_b) > 1)
	{
		first_node_b = ft_lst_del_first(ptr_first_node_b);
		ft_add_node(ptr_first_node_b, first_node_b);
		write(1, "rrb\n", 4);
	}
}

void	ft_push_b(t_node **ptr_first_node_a, t_node **ptr_first_node_b)
{
	t_node	*last_node_a;

	if (ptr_first_node_a != NULL && ptr_first_node_b != NULL
		&& ft_size_lst(ptr_first_node_a) > 0)
	{
		last_node_a = ft_lst_del_last(ptr_first_node_a);
		ft_add_node(ptr_first_node_b, last_node_a);
		write(1, "pb\n", 3);
	}
}

void	ft_push_a(t_node **ptr_first_node_a, t_node **ptr_first_node_b)
{
	t_node	*last_node_b;

	if (ptr_first_node_a != NULL && ptr_first_node_b != NULL
		&& ft_size_lst(ptr_first_node_b) > 0)
	{
		last_node_b = ft_lst_del_last(ptr_first_node_b);
		ft_add_node(ptr_first_node_a, last_node_b);
		write(1, "pa\n", 3);
	}
}
