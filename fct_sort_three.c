/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_sort_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:08:58 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/02 22:47:23 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    part_1(t_node **ptr_frst_a, t_node *top, t_node *mid, t_node *b)
{
    if (top->value > mid->value       //2 1 3
        && mid->value < b->value 
        && b->value > top->value)
    {
        ft_swap_a(ptr_frst_a);
    }
    if (top->value > mid->value        //T=3 M=1 B=2
        && mid->value < b->value 
        && b->value < top->value)
    {
        ft_rotate_a(ptr_frst_a);
    }
    if (top->value < mid->value
        && mid->value > b->value
        && b->value < top->value) //T=2 M=3 B=1
    {
        ft_reverse_rotate_a(ptr_frst_a);
    }
}

static void    part_2(t_node **ptr_frst_a, t_node *top, t_node *mid, t_node *b)
{

    if (top->value > mid->value    //T=3 M=2 B=1
        && mid->value > b->value
        && b->value < top->value)
    {
        ft_swap_a(ptr_frst_a);
        ft_reverse_rotate_a(ptr_frst_a);
    }
    if (top->value < mid->value    //T=1 M=3 B=2
        && mid->value > b->value
        && b->value > top->value)
    {
        ft_swap_a(ptr_frst_a);
        ft_rotate_a(ptr_frst_a);
    }
}

void    ft_sort_three(t_node **ptr_first_node_a)
{
    t_node  *bottom;
    t_node  *mid;
    t_node  *top;

    top = ft_last_node(ptr_first_node_a);
    mid = top->previous;
    bottom = mid->previous;

    if (top != NULL && mid != NULL && bottom != NULL)
    {
        part_1(ptr_first_node_a, top, mid, bottom);
        part_2(ptr_first_node_a, top, mid, bottom);
    }
}
