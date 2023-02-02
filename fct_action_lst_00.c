/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_action_lst_00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:42:39 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/02 21:46:12 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_node **ptr_first_node_a)
{
	t_node	*last_node;
    t_node  *second_last_node;

    if (*ptr_first_node_a != NULL && ft_size_lst(ptr_first_node_a) > 1)
    {
        last_node = ft_lst_del_last(ptr_first_node_a);
        second_last_node = ft_lst_del_last(ptr_first_node_a);
        ft_add_node(ptr_first_node_a, last_node);
        ft_add_node(ptr_first_node_a, second_last_node);
        write(1,"sa\n",3);   
    }
}

void	ft_swap_b(t_node **ptr_first_node_b)
{
	t_node	*last_node;
    t_node  *second_last_node;

    if (*ptr_first_node_b != NULL && ft_size_lst(ptr_first_node_b) > 1)
    {
        last_node = ft_lst_del_last(ptr_first_node_b);
        second_last_node = ft_lst_del_last(ptr_first_node_b);
        ft_add_node(ptr_first_node_b, last_node);
        ft_add_node(ptr_first_node_b, second_last_node);
        write(1,"sb\n",3);   
    }
}

void	ft_rotate_a(t_node **ptr_first_node_a)
{
	t_node	*last_node_a;

    if (*ptr_first_node_a != NULL && ft_size_lst(ptr_first_node_a) > 1)
    {
	    last_node_a = ft_lst_del_last(ptr_first_node_a);
    	ft_add_node_front(ptr_first_node_a, last_node_a);
        write(1, "ra\n", 3);
    }
}

void	ft_rotate_b(t_node **ptr_first_node_b)
{
	t_node	*last_node_b;

    if (*ptr_first_node_b != NULL && ft_size_lst(ptr_first_node_b) > 1)
    {
	    last_node_b = ft_lst_del_last(ptr_first_node_b);
    	ft_add_node_front(ptr_first_node_b, last_node_b);
        write(1, "rb\n", 3);
    }
}