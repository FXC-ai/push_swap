/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_big_sort_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:25:18 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/03 12:31:04 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_srch_from_bottom_a(t_node **ptr_first_node, int ind_min, int ind_max)
{
	int		i;
	t_node	*current_node;

	i = 1;
	current_node = *ptr_first_node;
	if (current_node != NULL && ind_min < ind_max)
	{
		while (current_node != NULL)
		{
			if (current_node->ind >= ind_min && current_node->ind <= ind_max)
			{
				return (i);
			}
			i++;
			current_node = current_node->next;
		}
	}
	return (-1);
}

int	ft_srch_from_top_a(t_node **ptr_first_node, int ind_min, int ind_max)
{
	int		i;
	t_node	*current_node;

	i = 0;
	current_node = ft_last_node(ptr_first_node);
	if (current_node != NULL && ind_min < ind_max)
	{
		while (current_node != NULL)
		{
			if (current_node->ind >= ind_min && current_node->ind <= ind_max)
			{
				return (i);
			}
			i++;
			current_node = current_node->previous;
		}
	}
	return (-1);
}

int	ft_srch_from_bottom_b(t_node **ptr_first_node, int ind_value)
{
	int		i;
	t_node	*current_node;

	i = 1;
	current_node = *ptr_first_node;
	if (current_node != NULL && ind_value > 0)
	{
		while (current_node != NULL)
		{
			if (current_node->ind == ind_value)
			{
				return (i);
			}
			i++;
			current_node = current_node->next;
		}
	}
	return (-1);
}

int	ft_srch_from_top_b(t_node **ptr_first_node, int ind_value)
{
	int		i;
	t_node	*current_node;

	i = 0;
	current_node = ft_last_node(ptr_first_node);
	if (current_node != NULL && ind_value > 0)
	{
		while (current_node != NULL)
		{
			if (current_node->ind == ind_value)
			{
				return (i);
			}
			i++;
			current_node = current_node->previous;
		}
	}
	return (-1);
}

int	ft_calculate_nb_chunk(int tablen)
{
	if (tablen > 5 && tablen < 21)
	{
		return (2);
	}
	if (tablen == 100)
	{
		return (5);
	}
	else if (tablen == 500)
	{
		return (12);
	}
	else
	{
		return (((tablen * 7) / 400) + 3);
	}
}
