/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_chained_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:25:18 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/02 22:43:28 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"








int ft_srch_from_bottom_a(t_node **ptr_first_node, int ind_min, int ind_max)
{
    int     i;
    t_node  *current_node;
    
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

int ft_srch_from_top_a(t_node **ptr_first_node, int ind_min, int ind_max)
{
    int     i;
    t_node  *current_node;
    
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

int ft_srch_from_bottom_b(t_node **ptr_first_node, int ind_value)
{
    int     i;
    t_node  *current_node;
    
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
    printf("\nIl y a un pb avec ft_srch_from_bottom_b\n");
    return (-1);
}

int ft_srch_from_top_b(t_node **ptr_first_node, int ind_value)
{
    int     i;
    t_node  *current_node;
    
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
    printf("Il y a un pb avec ft_srch_from_bottom_b\n");
    return (-1);
}

/*
int ft_srch_value_bottom_b(t_node **ptr_first_node_a, int ind_to_find)
{
    int     i;
    t_node  *current_node;
    
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


}*/

/*
int main()
{

    int     tablen;
    int     tab_int[10] = {10,9,2,1,6,7,4,8,3,5};
    int     nb_chunk;
    int     min_chunk;
    int     max_chunk;
    int     nb_rotate;
    int     nb_rev_rotate;
    
    tablen = 10;
    nb_chunk = 2;
    t_node *first_node_a = NULL;
    t_node **ptr_first_node_a = &first_node_a;

    t_node *first_node_b = NULL;
    t_node **ptr_first_node_b = &first_node_b;
    
    first_node_a = ft_create_lst(tab_int, tablen);

    ft_sort_int_tab(tab_int, tablen);
    ft_set_index_lst(ptr_first_node_a, tab_int, tablen);

    min_chunk = ft_find_min_chunk(tablen, nb_chunk, 1);
    max_chunk = ft_find_max_chunk(tablen, nb_chunk, 1);

    nb_rotate = ft_srch_from_top_a(ptr_first_node_a, min_chunk, max_chunk);
    nb_rev_rotate = ft_srch_from_bottom_a(ptr_first_node_a, min_chunk, max_chunk);
    
    printf("\nmin_chunk = %d, max_chunk = %d, nb_rotate = %d, nb_rev_rotate = %d\n\n",
            min_chunk, max_chunk, nb_rotate, nb_rev_rotate);

    ft_display_lst(ptr_first_node_a, "LISTE A");

    if (nb_rotate <= nb_rev_rotate)
    {
        while (nb_rotate > 0)
        {
            ft_rotate_a(ptr_first_node_a);
            nb_rotate--;
        }
    }
    else
    {
        while (nb_rev_rotate > 0)
        {
            ft_reverse_rotate_a(ptr_first_node_a);
            nb_rev_rotate--;
        }
    }
    
    //ft_push_b(ptr_first_node_a,ptr_first_node_b);

    ft_display_lst(ptr_first_node_a, "LISTE A");
    ft_display_lst(ptr_first_node_b, "LISTE B");





    //printf("\nind from bottom = %d\n", ft_srch_from_bottom(ptr_first_node_a, 5, 9));
    //printf("\nind from top    = %d\n", ft_srch_from_top(ptr_first_node_a, 5, 9));
    
    ft_destruct_lst(ptr_first_node_a);
    ft_destruct_lst(ptr_first_node_b);

    return 0;
}
*/