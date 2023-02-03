/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_chained_lst_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:33:04 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/03 12:40:22 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_last_node(t_node **ptr_first_node)
{
	t_node	*current_node;

	if (ptr_first_node == NULL || *ptr_first_node == NULL)
	{
		return (NULL);
	}
	current_node = *ptr_first_node;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	return (current_node);
}

t_node	*ft_lst_del_last(t_node **ptr_first_node)
{
	t_node	*last_node;

	if (*ptr_first_node == NULL)
	{
		return (NULL);
	}
	last_node = ft_last_node(ptr_first_node);
	if (last_node->previous == NULL && last_node->next == NULL)
	{
		*ptr_first_node = NULL;
		return (last_node);
	}
	else
	{
		(last_node->previous)->next = NULL;
		last_node->previous = NULL;
		last_node->next = NULL;
		return (last_node);
	}
}

t_node	*ft_lst_del_first(t_node **ptr_first_node)
{
	t_node	*first_node;

	if (*ptr_first_node == NULL)
	{
		return (NULL);
	}
	first_node = *ptr_first_node;
	if (first_node->previous == NULL && first_node->next == NULL)
	{
		*ptr_first_node = NULL;
		return (first_node);
	}
	else
	{
		(first_node->next)->previous = NULL;
		*ptr_first_node = first_node->next;
		first_node->previous = NULL;
		first_node->next = NULL;
		return (first_node);
	}
}

void	ft_add_node_front(t_node **ptr_first_node, t_node *node)
{
	if (ptr_first_node != NULL)
	{
		if (*ptr_first_node != NULL)
		{
			node->next = *ptr_first_node;
		}
		(*ptr_first_node)->previous = node;
		*ptr_first_node = node;
	}
}

int	ft_size_lst(t_node **ptr_first_node)
{
	int		count;
	t_node	*current_node;

	count = 0;
	current_node = *ptr_first_node;
	while (current_node != NULL)
	{
		current_node = current_node->next;
		count++;
	}
	return (count);
}
