/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_algo_launcher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:08:11 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/03 12:28:20 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_choose_algo(t_node **ptr_first_a, t_node **ptr_first_b, int tablen)
{
	if (tablen == 2)
		ft_sort_two(ptr_first_a);
	else if (tablen == 3)
		ft_sort_three(ptr_first_a);
	else if (tablen == 4)
		ft_sort_four(ptr_first_a, ptr_first_b);
	else if (tablen == 5)
		ft_sort_five(ptr_first_a, ptr_first_b);
	else
		ft_st(ptr_first_a, ptr_first_b, tablen);
}

int	ft_launch_algo(int *tab_int, int tablen)
{
	t_node	*first_node_a;
	t_node	*first_node_b;
	t_node	**ptr_first_node_a;
	t_node	**ptr_first_node_b;

	first_node_a = ft_create_lst(tab_int, tablen);
	ptr_first_node_a = &first_node_a;
	first_node_b = NULL;
	ptr_first_node_b = &first_node_b;
	ft_sort_int_tab(tab_int, tablen);
	ft_set_index_lst(ptr_first_node_a, tab_int, tablen);
	if (ft_check_is_sorted(ptr_first_node_a) == 1)
	{
		ft_destruct_lst(ptr_first_node_a);
		free(tab_int);
		return (0);
	}
	ft_choose_algo(ptr_first_node_a, ptr_first_node_b, tablen);
	ft_destruct_lst(ptr_first_node_a);
	ft_destruct_lst(ptr_first_node_b);
	free(tab_int);
	return (0);
}
