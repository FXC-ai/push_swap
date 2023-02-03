/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_sort_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:43:10 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/03 13:21:33 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cas1(int pos5, t_node **ptr_first_node_a, t_node **ptr_first_node_b)
{
	while (pos5 > 0)
	{
		ft_rotate_a(ptr_first_node_a);
		pos5--;
	}
	ft_push_b(ptr_first_node_a, ptr_first_node_b);
	ft_sort_four(ptr_first_node_a, ptr_first_node_b);
	ft_push_a(ptr_first_node_a, ptr_first_node_b);
	ft_rotate_a(ptr_first_node_a);
}

static void	cas2(int pos5, t_node **ptr_first_node_a, t_node **ptr_first_node_b)
{
	pos5 = 5 - pos5;
	while (pos5 > 0)
	{
		ft_reverse_rotate_a(ptr_first_node_a);
		pos5--;
	}
	ft_push_b(ptr_first_node_a, ptr_first_node_b);
	ft_sort_four(ptr_first_node_a, ptr_first_node_b);
	ft_push_a(ptr_first_node_a, ptr_first_node_b);
	ft_rotate_a(ptr_first_node_a);
}

void	ft_sort_five(t_node **ptr_first_node_a, t_node **ptr_first_node_b)
{
	int		pos_5;
	t_node	*current_node;

	pos_5 = 0;
	current_node = *ptr_first_node_a;
	if (ft_check_is_sorted(ptr_first_node_a) == 0)
	{
		while (current_node->ind != 5)
		{
			pos_5++;
			current_node = current_node->next;
		}
		pos_5 = 4 - pos_5;
		if (pos_5 <= 2)
			cas1(pos_5, ptr_first_node_a, ptr_first_node_b);
		else
			cas2(pos_5, ptr_first_node_a, ptr_first_node_b);
	}
}
