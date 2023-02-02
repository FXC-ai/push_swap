/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:16:37 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/02 09:53:24 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_find_max_chunk(int size_stack, int nb_chunk, int id_chunk)
{

    int size_chunk;
    int max;

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

int ft_find_min_chunk(int size_stack, int nb_chunk, int id_chunk)
{

    int size_chunk;
    int min;

    size_chunk = size_stack / nb_chunk;
    min = 0;
    if (id_chunk == 1)
    {
        min = 1;
    }
    else
    {
        min = (id_chunk-1) * size_chunk + 1;
    }
    return (min);
}



int main()
{
    ft_find_min_chunk(148, 5, 1);
    ft_find_max_chunk(148, 5, 1);

    ft_find_min_chunk(148, 5, 2);
    ft_find_max_chunk(148, 5, 2);
    
    ft_find_min_chunk(148, 5, 3);
    ft_find_max_chunk(148, 5, 3);
    
    ft_find_min_chunk(148, 5, 4);
    ft_find_max_chunk(148, 5, 4);
    
    ft_find_min_chunk(148, 5, 5);
    ft_find_max_chunk(148, 5, 5);
    return 0;
}
