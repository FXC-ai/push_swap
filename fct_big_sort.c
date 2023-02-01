/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:16:37 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/01 20:43:52 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_find_max_chunk(int size_stack, int nb_chunk, int id_chunk)
{

    int size_chunk;
    int size_last_chunk;
    int max;

    size_chunk = size_stack / nb_chunk;
    size_last_chunk = size_stack % nb_chunk;

    printf("size_chunk = %d, size_last_chunk = %d \n", size_chunk, size_last_chunk);

    if (id_chunk == nb_chunk)
    {
        max = size_stack;
    }
    else
    {
        max = id_chunk * size_chunk;
    }
    printf("max = %d \n", max);
    return (max);
}

int main()
{
    ft_find_max_chunk(148, 5, 1);
    ft_find_max_chunk(148, 5, 2);
    ft_find_max_chunk(148, 5, 3);
    ft_find_max_chunk(148, 5, 4);
    ft_find_max_chunk(148, 5, 5);
    return 0;
}
