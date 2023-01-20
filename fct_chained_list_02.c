/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_chained_list_02.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:03:30 by fcoindre          #+#    #+#             */
/*   Updated: 2023/01/20 17:04:24 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node **first_node)
{

	t_node	*last_node;
	t_node	*penultimate_node;
	t_node	*second_penultimate_node;

	t_node	*previous;

	last_node = ft_last_node(first_node);
	penultimate_node = last_node->previous;
	second_penultimate_node = penultimate_node->previous;

	previous = penultimate_node->previous;
	last_node->next = penultimate_node;

	penultimate_node->previous = last_node;
	penultimate_node->next = NULL;
	last_node->previous = previous;

	second_penultimate_node->next = last_node;

}

void	ft_rotate(t_node **ptr_first_node)
{
	t_node	*last_node;
	t_node	*penultimate_node;
	t_node	*first_node;

	last_node = ft_last_node(ptr_first_node);
	penultimate_node = last_node->previous;
	first_node = *ptr_first_node;

	penultimate_node->next = NULL;
	last_node->previous = NULL;
	ft_add_node_front(ptr_first_node, last_node);
}


void	ft_reverse_rotate(t_node **ptr_first_node)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*last_node;

	first_node = *ptr_first_node;
	second_node = first_node->next;
	last_node = ft_last_node(ptr_first_node);

	ft_add_node(ptr_first_node, first_node);
	first_node->next = NULL;
	second_node->previous = NULL;
	*ptr_first_node = second_node;
}
