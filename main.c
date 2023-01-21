/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:15:14 by fcoindre          #+#    #+#             */
/*   Updated: 2023/01/21 15:28:47 by fcoindre         ###   ########.fr       */
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
        //printf("%ld | %d\n", tab_long[i], tab_int[i]);
        i++;
    }
    free(tab_long);
    return (tab_int);
}

int ft_sort_check(t_node **ptr_first_node)
{
    t_node  *current_node;

    current_node = *ptr_first_node;
    while (current_node->next != NULL)
    {
        if (current_node->value > (current_node->next)->value)
        {
            return (0);
        }
        current_node = current_node->next;
    }
    return (1);
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
    
    //printf("tablen = %d\n", tablen);
    tab_int = ft_convert_longtoint(tablen, tab_long);

    t_node  *stack1 = ft_create_lst(tab_int, tablen);
    free(tab_int);

    printf("\n\n----------------DISPLAY BEGIN----------------\n\n");


    if (ft_sort_check(&stack1) == 1)
    {
        ft_destruct_lst(&stack1);
        return (0);
    }

    

    ft_display_lst(&stack1);
    ft_destruct_lst(&stack1);

    printf("\n\n----------------DISPLAY   END----------------\n\n");

    //printf("args_valid = %d", args_valid);

    //printf("\n\n\n\n%ld\n\n\n", tab_long[0]);



    /*
    printf("\n\n\n\n%ld\n\n\n", tab_long[1]);
    printf("\n\n\n\n%ld\n\n\n", tab_long[2]);
    printf("\n\n\n\n%ld\n\n\n", tab_long[3]);
    printf("\n\n\n\n%ld\n\n\n", tab_long[4]);
    
    
	t_node *node0 = ft_new_node(12);
	t_node *node1 = ft_new_node(42);
    int tab[9] = {78,42,24, 87, 44, 120, 950, 1001, -83};
    t_node *node00;
    ft_add_node(&node0, node1);
    node00 = ft_create_lst(tab, 9);
	ft_display_node(node0);
    printf("\n");
    printf("SWAP TEST :\n");
    ft_display_lst(&node00);
    printf("\n");
    ft_swap(&node00);
    ft_display_lst(&node00);
    printf("\n");
    
    printf("ROTATE TEST :\n");
    ft_display_lst(&node00);
    printf("\n");
    ft_rotate(&node00);
    ft_display_lst(&node00);
    printf("\n");
    printf("REVERSE ROTATE TEST :\n");
    ft_display_lst(&node00);
    printf("\n");
    ft_reverse_rotate(&node00);
    ft_display_lst(&node00);
    printf("\n");
    ft_destruct_lst(&node00);
    ft_destruct_node(node0);
    ft_destruct_node(node1);
    */
    return 0;
}