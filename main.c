/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:19:41 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/02 19:28:17 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_calculate_nb_chunk(int tablen)
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

char    **ft_create_tab_char(int argc, char *argv[])
{
    char    *args;
    char    **tab_char;

    if (argc == 2)
    {
        args = ft_strdup(argv[1]);
    }
    else
    {
        args = ft_join_args(argc , argv);
    }

    tab_char = ft_split(args, ' ');
    free(args);
    return (tab_char);

}


void    ft_core_algo_2(t_node **ptr_first_node_a, t_node **ptr_first_node_b, int i)
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
        ft_core_algo_2(ptr_first_node_a, ptr_first_node_b, i);
        i--;
    }
}

void    ft_core_algo_1(t_node **ptr_first_node_a, t_node **ptr_first_node_b, int min_chunk, int max_chunk)
{
    int nb_rotate;
    int nb_rev_rotate;

    nb_rotate = ft_srch_from_top_a(ptr_first_node_a, min_chunk, max_chunk);
    nb_rev_rotate = ft_srch_from_bottom_a(ptr_first_node_a, min_chunk, max_chunk);        
    if (nb_rotate != -1 && nb_rev_rotate != -1)
    {
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
    }
}

void    ft_st1(t_node **ptr_first_node_a, t_node **ptr_first_node_b, int min_chunk, int max_chunk)
{
    int i;

    i = 0;
    while (i <= (max_chunk - min_chunk))
    {
        ft_core_algo_1(ptr_first_node_a, ptr_first_node_b, min_chunk, max_chunk);
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

void    ft_choose_algo(t_node **ptr_first_node_a, t_node **ptr_first_node_b, int tablen)
{
    if (tablen == 2)
        ft_sort_two(ptr_first_node_a);
    else if (tablen == 3)
        ft_sort_three(ptr_first_node_a);
    else if (tablen == 4)
        ft_sort_four(ptr_first_node_a, ptr_first_node_b);
    else if (tablen == 5)
        ft_sort_five(ptr_first_node_a, ptr_first_node_b);
    else
        ft_st(ptr_first_node_a, ptr_first_node_b, tablen);
}

int    ft_launch_algo(int *tab_int, int tablen)
{
    t_node  *first_node_a;
    t_node  *first_node_b;
    t_node  **ptr_first_node_a;
    t_node  **ptr_first_node_b;

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

int ft_check_int_double(char **tab_char, long *tab_long, int tablen)
{
    if (ft_check_args_int(tab_char, tab_long, tablen) == 0)
    {
        return (0);
    }
    if (ft_check_args_double(tab_char, tab_long, tablen) == 0)
    {
        return (0);
    }
    return (1);
}

int main(int argc, char *argv[])
{
    char    **tab_char;
    long    *tab_long;
    int     tablen;
    int     *tab_int;

    tab_int = NULL;
    tablen = argc - 1;
    if (argc == 1)
        return (0);
    tab_char = ft_create_tab_char(argc, argv);
    tablen = ft_size_table(tab_char);
    if (tablen == 0)
    {
        free(tab_char);
        return (0);
    }
    if (ft_check_args_number(tab_char, tablen) == 0)
        return (0);
    tab_long = ft_create_tab_long(tab_char, tablen);
    if (ft_check_int_double(tab_char, tab_long, tablen) == 0)
        return (0);
    tab_int = ft_convert_longtoint(tab_long, tablen);
    ft_free_tab_char(tab_char, tablen);
    ft_launch_algo(tab_int, tablen);
    return (0);
}

