/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_chained_list_01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:07:01 by fcoindre          #+#    #+#             */
/*   Updated: 2023/01/20 17:14:14 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_last_node(t_node **first_node)
{
	t_node *current_node;

	current_node = *first_node;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	return current_node;
}

t_node	*ft_create_lst(int *tab, int size_tab)
{
	t_node	*current_node;
	t_node	*first_node;

	size_tab--;
	first_node = ft_new_node(tab[size_tab]);
	size_tab--;
	while (size_tab >= 0)
	{
		current_node = ft_new_node(tab[size_tab]);
		ft_add_node(&first_node, current_node);
		size_tab--;
	}
	return	(first_node);
}

void	ft_destruct_lst(t_node **first_node)
{
	t_node	*current_node;
	t_node	*next_node;

	next_node = NULL;
	current_node = *first_node;
	while (current_node->next != NULL)
	{
		next_node = current_node->next;
		ft_destruct_node(current_node);
		current_node = next_node;
		next_node = NULL;
	}
	free(current_node);
}

void	ft_display_lst(t_node **first_node)
{
	t_node	*current_node;
	int		count;

	current_node = *first_node;
	count = 0;
	while (current_node->next != NULL)
	{
		ft_printf("Index = %d : ", count);
		ft_display_node(current_node);
		current_node = current_node->next;
		count++;
	}
	ft_printf("Index = %d : ", count);
	ft_display_node(current_node);
}
