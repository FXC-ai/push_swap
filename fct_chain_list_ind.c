/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_chain_list_ind.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:12:06 by fcoindre          #+#    #+#             */
/*   Updated: 2023/01/24 14:00:16 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
    int             ind;
	struct s_node	*previous;
	struct s_node	*next;
} t_node;

typedef struct s_stacks
{
	t_node	**a;
	t_node	**b;
} t_stacks;

t_node	*ft_new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
    node->ind = -1;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}


void	ft_destruct_node(t_node *node)
{
	if (node != NULL)
	{
		node->previous = NULL;	
		node->next = NULL;
		free(node);
	}
}

t_node	*ft_last_node(t_node **ptr_first_node)
{
	t_node *current_node;

    if (ptr_first_node == NULL || *ptr_first_node == NULL)
    {
        return (NULL);
    }
    
	current_node = *ptr_first_node;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	return current_node;
}

void	ft_add_node(t_node **ptr_first_node, t_node *new_node)
{
	t_node	*last_node;

	last_node = ft_last_node(ptr_first_node);
	if (ptr_first_node != NULL)
	{
		if (*ptr_first_node == NULL)
			*ptr_first_node = new_node;
		if (last_node != NULL)
		{
			last_node->next = new_node;
			new_node->previous = last_node;
		}
	}
}

void	ft_add_node_front(t_node **ptr_first_node, t_node *node)
{
	if (ptr_first_node)
	{
		if (*ptr_first_node)
			node->next = *ptr_first_node;
			(*ptr_first_node)->previous = node;
		*ptr_first_node = node;
	}
}

void	ft_display_node(t_node	*node)
{
	ft_printf("[%p] {value = %d | indice = %d | previous = %p | next = %p}\n", 
                        node, 
                        node->value,
                        node->ind,
                        node->previous, 
                        node->next);
}

void	ft_display_lst(t_node **first_node)
{
	t_node	*current_node;
	int		count;

	current_node = *first_node;
	count = 0;
    if (*first_node != NULL)
    {
	    while (current_node->next != NULL)
	    {
		    ft_printf("Index = %d : ", count);
		    ft_display_node(current_node);
		    current_node = current_node->next;
		    count++;
	    }
	    ft_printf("Index = %d : ", count);
	    ft_display_node(current_node);
    }
    else
    {
        ft_printf("The stack is empty.\n");
    }
}

t_node	*ft_create_lst(int *tab, int size_tab)
{
	t_node	*current_node;
	t_node	*first_node;

	size_tab--;
	first_node = ft_new_node(tab[size_tab]);
	size_tab--;
	while (size_tab >= 0)
	{
		current_node = ft_new_node(tab[size_tab]);
		ft_add_node(&first_node, current_node);
		size_tab--;
	}
	return	(first_node);
}

void	ft_destruct_lst(t_node **ptr_first_node)
{
	t_node	*current_node;
	t_node	*next_node;

	next_node = NULL;
	current_node = *ptr_first_node;
    if (current_node != NULL)
    {
	    while (current_node->next != NULL)
	    {
		    next_node = current_node->next;
		    ft_destruct_node(current_node);
		    current_node = next_node;
		    next_node = NULL;
	    }
	    free(current_node);
    }
}

void	ft_swap_a(t_node **ptr_first_node)
{
	t_node	*last_node;
	t_node	*penultimate_node;
	t_node	*second_penultimate_node;
	t_node	*previous;

	last_node = ft_last_node(ptr_first_node);
	penultimate_node = last_node->previous;
    second_penultimate_node = NULL;
    previous = NULL;
    if (last_node != NULL && penultimate_node != NULL)
    {
	    second_penultimate_node = penultimate_node->previous;
	    previous = penultimate_node->previous;
        last_node->next = penultimate_node;
    	penultimate_node->previous = last_node;
    	penultimate_node->next = NULL;
    	last_node->previous = previous;
        write(1,"sa\n",3);
    }
    if (second_penultimate_node != NULL)
	    second_penultimate_node->next = last_node;
    else
        *ptr_first_node = last_node;
}

void	ft_swap_b(t_node **ptr_first_node)
{
	t_node	*last_node;
	t_node	*penultimate_node;
	t_node	*second_penultimate_node;
	t_node	*previous;

	last_node = ft_last_node(ptr_first_node);
	penultimate_node = last_node->previous;
    second_penultimate_node = NULL;
    previous = NULL;
    if (last_node != NULL && penultimate_node != NULL)
    {
	    second_penultimate_node = penultimate_node->previous;
	    previous = penultimate_node->previous;
        last_node->next = penultimate_node;
    	penultimate_node->previous = last_node;
    	penultimate_node->next = NULL;
    	last_node->previous = previous;
        write(1,"sb\n",3);
    }
    if (second_penultimate_node != NULL)
	    second_penultimate_node->next = last_node;
    else
        *ptr_first_node = last_node;
}

void	ft_rotate_a(t_node **ptr_first_node)
{
	t_node	*last_node;
	t_node	*penultimate_node;
	t_node	*first_node;

	last_node = ft_last_node(ptr_first_node);
	penultimate_node = last_node->previous;
	first_node = *ptr_first_node;

    if (last_node != first_node)
    {
	    penultimate_node->next = NULL;
	    last_node->previous = NULL;
	    ft_add_node_front(ptr_first_node, last_node);
        write(1,"ra\n",3);
    }
}

void	ft_reverse_rotate(t_node **ptr_first_node)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*last_node;

	first_node = *ptr_first_node;
	second_node = first_node->next;
	last_node = ft_last_node(ptr_first_node);

    if (last_node != first_node)
    {
    	ft_add_node(ptr_first_node, first_node);
    	first_node->next = NULL;
    	second_node->previous = NULL;
    	*ptr_first_node = second_node;
    }
}

int ft_stack_is_empty(t_node **ptr_first_node)
{
    if (*ptr_first_node == NULL)
    {
        return (1);
    }
    return (0);
}

t_node    *ft_lst_del_last(t_node **ptr_first_node)
{
    t_node  *last_node;

    last_node = ft_last_node(ptr_first_node);
    if (ft_stack_is_empty(ptr_first_node) == 1)
    {
        return (NULL);
    }
    else if (last_node->previous == NULL)
    {
        *ptr_first_node = NULL;
        last_node->previous = NULL;
        last_node->next = NULL;
        return (last_node);
    }
    else
    {
        (last_node->previous)->next = NULL;
        last_node->previous = NULL;
        last_node->next = NULL;
        return (last_node);
    }
}

void ft_push_b(t_node **ptr_first_node_a, t_node **ptr_first_node_b)
{
    t_node  *last_node_a;
    t_node  *last_node_b;

    if (ft_stack_is_empty(ptr_first_node_a) == 0)
    {
        last_node_a = ft_last_node(ptr_first_node_a);

        if (ft_stack_is_empty(ptr_first_node_b) == 1)
        {
            *ptr_first_node_b = last_node_a;
            ft_lst_del_last(ptr_first_node_a);
        }
        else
        {
            last_node_b = ft_last_node(ptr_first_node_b);
            last_node_b->next = ft_lst_del_last(ptr_first_node_a);
            last_node_a->previous = last_node_b;
        }
    }
}

void ft_push_a(t_node **ptr_first_node_a, t_node **ptr_first_node_b)
{
    t_node  *last_node_b;
    t_node  *last_node_a;

    if (ft_stack_is_empty(ptr_first_node_b) == 0)
    {
        last_node_b = ft_last_node(ptr_first_node_b);

        if (ft_stack_is_empty(ptr_first_node_a) == 1)
        {
            *ptr_first_node_a = last_node_b;
            ft_lst_del_last(ptr_first_node_b);
        }
        else
        {
            last_node_a = ft_last_node(ptr_first_node_a);
            last_node_a->next = ft_lst_del_last(ptr_first_node_b);
            last_node_b->previous = last_node_a;
        }
    }
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

int ft_size_lst(t_node **ptr_first_node)
{
    int     count;
    t_node  *current_node;

    count = 0;
    current_node = *ptr_first_node;
    while (current_node != NULL)
    {
        current_node = current_node->next;
        count++;
    }
    return count;
}

int ft_maxvalue_lst(t_node **ptr_first_node)
{

    int     max_value;
    t_node  *current_node;

    max_value = 0;
    current_node = *ptr_first_node;
    while (current_node != NULL)
    {
        if (current_node->value > max_value && current_node->ind == -1)
        {
            max_value = current_node->value;
        }
        current_node = current_node->next;
    }
    return max_value;    
}

int ft_minvalue_lst(t_node **ptr_first_node)
{
    int     min_value;
    t_node  *current_node;

    min_value = ft_maxvalue_lst(ptr_first_node);
    current_node = *ptr_first_node;
    while (current_node != NULL)
    {
        if (current_node->value < min_value && current_node->ind == -1)
        {
            min_value = current_node->value;
        }
        current_node = current_node->next;
    }
    return min_value;    
}

void    ft_index_lst(t_node **ptr_first_node)
{
    int i;
    int count;
    int size_list;
    t_node  *current_node;

    i = 0;
    count = 1;
    size_list = ft_size_lst(ptr_first_node);
    current_node = *ptr_first_node;
    while (i < size_list)
    {
        current_node = *ptr_first_node;
        while (current_node != NULL)
        {
            if (current_node->value == ft_minvalue_lst(ptr_first_node))
            {
                current_node->ind = count;
                count++;
            }
            current_node = current_node->next;
        }
        i++;
    }
}

void    ft_sort_two_nodes(t_node **ptr_first_node)
{
    t_node  *node1 = ft_last_node(ptr_first_node);
    t_node  *node0 = node1->previous;

    if (node0 != NULL && node1 != NULL)
    {
        if (node0->ind < node1->ind)
        {
            ft_swap_a(ptr_first_node);
        }
    }
}

void    ft_sort_three_nodes(t_node **ptr_first_node_a)
{
    t_node  *node0;
    t_node  *node1;
    t_node  *node2;

    node2 = ft_last_node(ptr_first_node_a);
    node1 = node2->previous;
    node0 = node1->previous;

    if (node0 != NULL && node1 != NULL && node2 != NULL)
    {
        if (node2->ind > node1->ind && node1->ind < node0->ind && node2->ind < node0->ind)
        {
            ft_swap_a(ptr_first_node_a);
        }
        if (node2->ind > node1->ind && node1->ind < node0->ind && node2->ind > node0->ind)
        {
            ft_rotate_a(ptr_first_node_a);
        }
        

    }
}


int main()
{
    int tab_int[3] = {20,10,30};

    t_node *first_node_a = NULL;
    t_node **ptr_first_node_a = &first_node_a;
    first_node_a = ft_create_lst(tab_int, 3);

    //t_node *first_node_b = NULL;
    //t_node **ptr_first_node_b = &first_node_b;

    //t_node **ptr_first_node_b = &first_node_a;
    
    //printf("\n\n----------------DISPLAY BEGIN----------------\n\n");

    //ft_display_lst(ptr_first_node_a);
    //printf("\n");

    ft_index_lst(ptr_first_node_a);
    ft_sort_three_nodes(ptr_first_node_a);

    //ft_display_lst(ptr_first_node_a);


    //printf("\n\n----------------DISPLAY   END----------------\n\n");
    ft_destruct_lst(ptr_first_node_a);
    
    return 0;
}
