/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:19:41 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/01 17:27:45 by fcoindre         ###   ########.fr       */
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

    //ft_display_lst(ptr_first_node_a, "Liste A");


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

	
    

    //ft_display_lst(ptr_first_node_a, "Liste A :");


    ft_destruct_lst(ptr_first_node_a);
    free(tab_int);

    return (0);
}