/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_sort_four.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:27:41 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/03 13:25:29 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_cas_1(t_node **ptr_first_node_a, t_node **ptr_first_node_b)
{
	ft_rotate_a(ptr_first_node_a);
	ft_push_a(ptr_first_node_a, ptr_first_node_b);
	ft_reverse_rotate_a(ptr_first_node_a);
}

static void	ft_cas_2(t_node **ptr_first_node_a, t_node **ptr_first_node_b)
{
	ft_reverse_rotate_a(ptr_first_node_a);
	ft_push_a(ptr_first_node_a, ptr_first_node_b);
	ft_rotate_a(ptr_first_node_a);
	ft_rotate_a(ptr_first_node_a);
}

void	ft_sort_four(t_node **ptr_first_node_a, t_node **ptr_first_node_b)
{
	t_node	*nod;

	if (ft_check_is_sorted(ptr_first_node_a) == 0)
	{
		ft_push_b(ptr_first_node_a, ptr_first_node_b);
		ft_sort_three(ptr_first_node_a);
		nod = ft_last_node(ptr_first_node_b);
		if (nod->ind < ft_last_node(ptr_first_node_a)->ind)
			ft_push_a(ptr_first_node_a, ptr_first_node_b);
		else if (nod->ind > ft_last_node(ptr_first_node_a)->ind
			&& nod->ind < ((ft_last_node(ptr_first_node_a))->previous)->ind)
			ft_cas_1(ptr_first_node_a, ptr_first_node_b);
		else if (nod->ind < (*ptr_first_node_a)->ind
			&& nod->ind > ((*ptr_first_node_a)->next)->ind)
			ft_cas_2(ptr_first_node_a, ptr_first_node_b);
		else
		{
			ft_push_a(ptr_first_node_a, ptr_first_node_b);
			ft_rotate_a(ptr_first_node_a);
		}
	}
}
