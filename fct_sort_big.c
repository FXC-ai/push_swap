/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_sort_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:00:38 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/02 23:04:42 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_cor_al2(t_node **ptr_first_node_a, t_node **ptr_first_node_b, int i)
{
    int nb_rotate;
    int nb_rev_rotate;

    nb_rev_rotate = ft_srch_from_bottom_b(ptr_first_node_b, i);
    nb_rotate = ft_srch_from_top_b(ptr_first_node_b, i);
    if (nb_rotate != -1 && nb_rev_rotate != -1)
    {
        if (nb_rotate <= nb_rev_rotate)
        {
            while (nb_rotate > 0)
            {
                ft_rotate_b(ptr_first_node_b);
                nb_rotate--;            
            }
        }
        else
        {
            while (nb_rev_rotate > 0)
            {
                ft_reverse_rotate_b(ptr_first_node_b);
                nb_rev_rotate--;
            }
        }
        ft_push_a(ptr_first_node_a, ptr_first_node_b);
    }
}

void    ft_st2(t_node **ptr_first_node_a, t_node **ptr_first_node_b, int tablen)
{
    int i;

    i = tablen;
    while (i > 0)
    {
        ft_cor_al2(ptr_first_node_a, ptr_first_node_b, i);
        i--;
    }
}

void    ft_cor_al1(t_node **ptr_first_a, t_node **ptr_first_b, int min, int max)
{
    int nb_rotate;
    int nb_rev_rotate;

    nb_rotate = ft_srch_from_top_a(ptr_first_a, min, max);
    nb_rev_rotate = ft_srch_from_bottom_a(ptr_first_a, min, max);        
    if (nb_rotate != -1 && nb_rev_rotate != -1)
    {
        if (nb_rotate <= nb_rev_rotate)
        {
            while (nb_rotate > 0)
            {
                ft_rotate_a(ptr_first_a);
                nb_rotate--;
            }
        }
        else
        {
            while (nb_rev_rotate > 0)
            {
                ft_reverse_rotate_a(ptr_first_a);
                nb_rev_rotate--;
            }
        }
        ft_push_b(ptr_first_a, ptr_first_b);
    }
}

void    ft_st1(t_node **ptr_first_a, t_node **ptr_first_b, int min, int max)
{
    int i;

    i = 0;
    while (i <= (max - min))
    {
        ft_cor_al1(ptr_first_a, ptr_first_b, min, max);
        i++;
    }
}

void    ft_st(t_node **ptr_first_node_a, t_node **ptr_first_node_b, int tablen)
{
    int nb_chunk;
    int id_chunk;
    int min_chunk;
    int max_chunk;

    nb_chunk = ft_calculate_nb_chunk(tablen);
    id_chunk = 1;
    while (id_chunk <= nb_chunk)
    {
        min_chunk = ft_find_min_chunk(tablen, nb_chunk, id_chunk);
        max_chunk = ft_find_max_chunk(tablen, nb_chunk, id_chunk);
        ft_st1(ptr_first_node_a, ptr_first_node_b, min_chunk, max_chunk);
        id_chunk++;
    }
    ft_st2(ptr_first_node_a, ptr_first_node_b, tablen);
}