/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:19:41 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/02 11:40:10 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(int argc, char *argv[])
{
    char    **tab_char;
    long    *tab_long;
    int     tablen;
    char    *args;
    int     *tab_int;

    t_node  *first_node_a;
    t_node  *first_node_b;
    t_node  **ptr_first_node_a;
    t_node  **ptr_first_node_b;

    int nb_chunk;
    int min_chunk;
    int max_chunk;
    int nb_rotate;
    int nb_rev_rotate;
    int i;

    tab_int = NULL;
    args = NULL;
    tablen = argc - 1;

    if (argc == 1)
    {
        return (0);
    }
    else if (argc == 2)
    {
        args = ft_strdup(argv[1]);
    }
    else
    {
        args = ft_join_args(argc , argv);
    }
    
    tab_char = ft_split(args, ' ');
    free(args);

    tablen = ft_size_table(tab_char);

    if (tablen == 0)
    {
        free(tab_char);
        return (0);
    }
    
    if (ft_check_args_number(tab_char, tablen) == 0)
    {
        write(2,"Error\n",6);
        ft_free_tab_char(tab_char, tablen);
        return (0);
    }

    tab_long = ft_create_tab_long(tab_char, tablen);

    if (ft_check_args_int(tab_long, tablen) == 0)
    {
        write(2,"Error\n",6);
        ft_free_tab_char(tab_char, tablen);
        free(tab_long);
        return (0);
    }
    
    if (ft_check_args_double(tab_long, tablen) == 0)
    {
        write(2,"Error\n",6);
        ft_free_tab_char(tab_char, tablen);
        free(tab_long);
        return (0);
    }
    
    tab_int = ft_convert_longtoint(tab_long, tablen);
    ft_free_tab_char(tab_char, tablen);

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
    
    if (tablen == 2)
    {
        ft_sort_two(ptr_first_node_a);
    }
    else if (tablen == 3)
    {
        ft_sort_three(ptr_first_node_a);
    }
    else if (tablen == 4)
    {
        ft_sort_four(ptr_first_node_a, ptr_first_node_b);
    }
    else if (tablen == 5)
    {
        ft_sort_five(ptr_first_node_a, ptr_first_node_b);
    }
    else
    {
        nb_chunk = 2;
        min_chunk = ft_find_min_chunk(tablen, nb_chunk, 1);
        max_chunk = ft_find_max_chunk(tablen, nb_chunk, 1);

        nb_rotate = ft_srch_from_top_a(ptr_first_node_a, min_chunk, max_chunk);
        nb_rev_rotate = ft_srch_from_bottom_a(ptr_first_node_a, min_chunk, max_chunk);
        
        printf("\nmin_chunk = %d, max_chunk = %d, nb_rotate = %d, nb_rev_rotate = %d\n\n",
                min_chunk, max_chunk, nb_rotate, nb_rev_rotate);

        printf("\n\n");
        //ft_display_lst(ptr_first_node_a, "LISTE A");

        
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
        
        ft_push_b(ptr_first_node_a,ptr_first_node_b);

        //ft_display_lst(ptr_first_node_a, "LISTE A");
        //ft_display_lst(ptr_first_node_b, "LISTE B");

    }

	


    ft_destruct_lst(ptr_first_node_a);
    ft_destruct_lst(ptr_first_node_b);
    free(tab_int);

    return (0);
}

