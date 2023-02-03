/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_chained_lst_00.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:21:55 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/03 12:36:45 by fcoindre         ###   ########.fr       */
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
	node->ind = -1;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void	ft_add_node(t_node **ptr_first_node, t_node *new_node)
{
	t_node	*last_node;

	last_node = ft_last_node(ptr_first_node);
	if (ptr_first_node != NULL)
	{
		if (*ptr_first_node == NULL)
		{
			*ptr_first_node = new_node;
		}
		if (last_node != NULL)
		{
			last_node->next = new_node;
			new_node->previous = last_node;
		}
	}
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

t_node	*ft_create_lst(int *tab, int size_tab)
{
	t_node	*current_node;
	t_node	*first_node;

	first_node = NULL;
	if (size_tab != 0 && tab != NULL)
	{
		size_tab--;
		first_node = ft_new_node(tab[size_tab]);
		size_tab--;
		while (size_tab >= 0)
		{
			current_node = ft_new_node(tab[size_tab]);
			ft_add_node(&first_node, current_node);
			size_tab--;
		}
	}
	return (first_node);
}

void	ft_destruct_lst(t_node **ptr_first_node)
{
	t_node	*current_node;
	t_node	*next_node;

	next_node = NULL;
	current_node = *ptr_first_node;
	if (current_node != NULL)
	{
		while (current_node->next != NULL)
		{
			next_node = current_node->next;
			ft_destruct_node(current_node);
			current_node = next_node;
			next_node = NULL;
		}
		free(current_node);
	}
}
