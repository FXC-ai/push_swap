/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_sort_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:16:37 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/03 14:34:30 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max_chunk(int size_stack, int nb_chunk, int id_chunk)
{
	int	size_chunk;
	int	max;

	size_chunk = size_stack / nb_chunk;
	max = 0;
	if (id_chunk == nb_chunk)
	{
		max = size_stack;
	}
	else
	{
		max = id_chunk * size_chunk;
	}
	return (max);
}

int	ft_find_min_chunk(int size_stack, int nb_chunk, int id_chunk)
{
	int	size_chunk;
	int	min;

	size_chunk = size_stack / nb_chunk;
	min = 0;
	if (id_chunk == 1)
	{
		min = 1;
	}
	else
	{
		min = (id_chunk - 1) * size_chunk + 1;
	}
	return (min);
}

int	ft_check_is_sorted(t_node **ptr_first_node)
{
	t_node	*current_node;

	current_node = *ptr_first_node;
	while (current_node->next != NULL)
	{
		if (current_node->value < (current_node->next)->value)
		{
			return (0);
		}
		current_node = current_node->next;
	}
	return (1);
}

void	ft_sort_two(t_node **ptr_first_node)
{
	t_node	*node1;
	t_node	*node0;

	node1 = ft_last_node(ptr_first_node);
	node0 = node1->previous;
	if (node0 != NULL && node1 != NULL)
	{
		if (node0->value < node1->value)
		{
			ft_swap_a(ptr_first_node);
		}
	}
}

void	ft_set_index_lst(t_node **ptr_first_node, int *tab_int, int tablen)
{
	int		i;
	t_node	*current_node;

	i = 0;
	current_node = *ptr_first_node;
	while (i < tablen)
	{
		current_node = *ptr_first_node;
		while (current_node != NULL)
		{
			if (current_node->value == tab_int[i])
			{
				current_node->ind = (i + 1);
			}
			current_node = current_node->next;
		}
		i++;
	}
}
