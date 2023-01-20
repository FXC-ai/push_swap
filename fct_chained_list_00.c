/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_chained_list_00.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:05:56 by fcoindre          #+#    #+#             */
/*   Updated: 2023/01/20 17:11:35 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void	ft_destruct_node(t_node *node)
{
	if (node != NULL)
	{
		node->previous = NULL;	
		node->next = NULL;
		free(node);
	}
}

void	ft_display_node(t_node	*node)
{
	ft_printf("[%p] {value = %d | previous = %p |next = %p}\n", node, node->value, node->previous, node->next);
}

void	ft_add_node(t_node **first_node, t_node *new_node)
{
	t_node	*last_node;

	last_node = ft_last_node(first_node);
	if (first_node != NULL)
	{
		if (*first_node == NULL)
			*first_node = new_node;
		if (last_node != NULL)
		{
			last_node->next = new_node;
			new_node->previous = last_node;
		}
	}
}

void	ft_add_node_front(t_node **ptr_first_node, t_node *node)
{
	if (ptr_first_node)
	{
		if (*ptr_first_node)
			node->next = *ptr_first_node;
			(*ptr_first_node)->previous = node;
		*ptr_first_node = node;
	}
}
