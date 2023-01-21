/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:15:14 by fcoindre          #+#    #+#             */
/*   Updated: 2023/01/21 19:09:57 by fcoindre         ###   ########.fr       */
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

void    ft_swap_in(t_node *node_min, t_node *node_max)
{
    t_node  *temp;
    t_node  *before_min = node_min->previous;
    t_node  *after_max = node_max->next;

    before_min->next = node_max;
    after_max->previous = node_min;

    temp = ft_new_node(node_min->value);
    temp->previous = node_min->previous;
    temp->next = node_min->next;

    node_min->previous = node_max;
    node_min->next = node_max->next;

    node_max->previous = temp->previous;
    node_max->next = node_min;
}

void    ft_swap_begin(t_node **stack, t_node *node_min, t_node *node_max)
{
    printf("\n");
    ft_display_node(node_min);
    ft_display_node(node_max);
    printf("\n");

    t_node  *after_max;

    after_max = node_max->next;
    after_max->previous = node_min;

    node_max->previous = NULL;
    node_max->next = node_min;

    node_min->previous = node_max;
    node_min->next = after_max;
    
    stack = &node_max;
    printf("\n");
    ft_display_node(node_max);
    ft_display_node(node_min);
    printf("\n");

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
    printf("\n");

    t_node *node_min = stack1;
    t_node *node_max = stack1->next;
    

    ft_swap_begin(&stack1, node_min, node_max);
    
    ft_display_lst(&stack1);
    
    ft_destruct_lst(&stack1);

    printf("\n\n----------------DISPLAY   END----------------\n\n");


    return 0;
}