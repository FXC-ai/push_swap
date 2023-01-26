/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:15:14 by fcoindre          #+#    #+#             */
/*   Updated: 2023/01/26 11:50:34 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *ft_convert_longtoint(int tablen, long *tab_long)
{
    int i;
    int *tab_int;

    tab_int = malloc(sizeof(int) * tablen);
    if (tab_int == NULL)
    {
        return (NULL);
    }
    i = 0;
    while (i < tablen)
    {
        tab_int[i] = (int) tab_long[i];
        i++;
    }
    free(tab_long);
    return (tab_int);
}

int main(int argc, char *argv[])
{

    long    *tab_long;
    int     args_valid;
    int     *tab_int;
    int     tablen;
    
    tablen = 0;
    tab_long = ft_args_management(argc, argv, &args_valid, &tablen);

    if (args_valid == 1)
    {
		write(2, "Error\n", 6);
        return (0);
    }
    else if (args_valid == -1 || tablen == 0)
    {
        return (0);
    }
    tab_int = ft_convert_longtoint(tablen, tab_long);

    t_node *first_node_a = NULL;
    t_node **ptr_first_node_a = &first_node_a;

    t_node *first_node_b = NULL;
    t_node **ptr_first_node_b = &first_node_b;
    

    first_node_a = ft_create_lst(tab_int, tablen);
    free(tab_int);


    
    if (ft_sort_check(ptr_first_node_a) == 0)
    {
        ft_index_lst(ptr_first_node_a);
        /*
        printf("---------Situation initiale--------\n");
        ft_display_lst(ptr_first_node_a);
        printf("\n");
        ft_display_lst(ptr_first_node_b);
        printf("\n");
        */

        if (ft_size_lst(ptr_first_node_a) == 3)
        {
            ft_sort_three_nodes(ptr_first_node_a);
        }
        else if (ft_size_lst(ptr_first_node_a) == 4)
        {
            ft_sort_four_nodes(ptr_first_node_a, ptr_first_node_b);
        }
        else if (ft_size_lst(ptr_first_node_a) == 5)
        {
            ft_sort_five_nodes(ptr_first_node_a, ptr_first_node_b);
        }
                
    }
    /*
    ft_display_lst(ptr_first_node_a);
    printf("\n");
    ft_display_lst(ptr_first_node_b);
    printf("\n");
    */
    ft_destruct_lst(ptr_first_node_a);

    return 0;
}


/*
    

    //t_node *first_node_b = NULL;
    //t_node **ptr_first_node_b = &first_node_b;

    //t_node **ptr_first_node_b = &first_node_a;
    
    //printf("\n\n----------------DISPLAY BEGIN----------------\n\n");

    //printf("\n");


    //ft_display_lst(ptr_first_node_a);


    //printf("\n\n----------------DISPLAY   END----------------\n\n");
    
    return 0;
}*/