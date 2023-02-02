/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_chained_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:25:18 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/02 20:28:48 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_node(t_node	*node)
{
    if (node != NULL)
    {
    	printf("[%p] {value = %d | indice = %d | previous = %p | next = %p}\n", 
                            node, 
                            node->value,
                            node->ind,
                            node->previous, 
                            node->next);
    }
}

void	ft_display_lst(t_node **first_node, char *name)
{
	t_node	*current_node;
	int		count;

	current_node = *first_node;
	count = 0;
    printf("\n%s :\n", name);
    if (*first_node != NULL)
    {
	    while (current_node->next != NULL)
	    {
		    printf("Index = %d : ", count);
		    ft_display_node(current_node);
		    current_node = current_node->next;
		    count++;
	    }
	    printf("Index = %d : ", count);
	    ft_display_node(current_node);
    }
    else
    {
        printf("The stack is empty.\n");
    }
    printf("\n");
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

t_node    *ft_lst_del_last(t_node **ptr_first_node)
{
    t_node  *last_node;

    if (*ptr_first_node == NULL)
    {
        return (NULL);
    }
    last_node = ft_last_node(ptr_first_node);
    if (last_node->previous == NULL && last_node->next == NULL)
    {
        *ptr_first_node = NULL;
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

t_node  *ft_lst_del_first(t_node **ptr_first_node)
{
    t_node  *first_node;

    if (*ptr_first_node == NULL)
    {
        return (NULL);
    }
    first_node = *ptr_first_node;
    
    if (first_node->previous == NULL && first_node->next == NULL)
    {
        *ptr_first_node = NULL;
        return (first_node);
    }
    else
    {
        (first_node->next)->previous = NULL;
        *ptr_first_node = first_node->next;
        first_node->previous = NULL;
        first_node->next = NULL;
        return (first_node);
    }
}

void	ft_add_node_front(t_node **ptr_first_node, t_node *node)
{
	if (ptr_first_node != NULL)
	{
		if (*ptr_first_node != NULL)
        {
			node->next = *ptr_first_node;
        }
		(*ptr_first_node)->previous = node;
		*ptr_first_node = node;
	}
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

void	ft_swap_a(t_node **ptr_first_node_a)
{
	t_node	*last_node;
    t_node  *second_last_node;

    if (*ptr_first_node_a != NULL && ft_size_lst(ptr_first_node_a) > 1)
    {
        last_node = ft_lst_del_last(ptr_first_node_a);
        second_last_node = ft_lst_del_last(ptr_first_node_a);
        ft_add_node(ptr_first_node_a, last_node);
        ft_add_node(ptr_first_node_a, second_last_node);
        write(1,"sa\n",3);   
    }
}

void	ft_swap_b(t_node **ptr_first_node_b)
{
	t_node	*last_node;
    t_node  *second_last_node;

    if (*ptr_first_node_b != NULL && ft_size_lst(ptr_first_node_b) > 1)
    {
        last_node = ft_lst_del_last(ptr_first_node_b);
        second_last_node = ft_lst_del_last(ptr_first_node_b);
        ft_add_node(ptr_first_node_b, last_node);
        ft_add_node(ptr_first_node_b, second_last_node);
        write(1,"sb\n",3);   
    }
}

void	ft_rotate_a(t_node **ptr_first_node_a)
{
	t_node	*last_node_a;

    if (*ptr_first_node_a != NULL && ft_size_lst(ptr_first_node_a) > 1)
    {
	    last_node_a = ft_lst_del_last(ptr_first_node_a);
    	ft_add_node_front(ptr_first_node_a, last_node_a);
        write(1, "ra\n", 3);
    }
}

void	ft_rotate_b(t_node **ptr_first_node_b)
{
	t_node	*last_node_b;

    if (*ptr_first_node_b != NULL && ft_size_lst(ptr_first_node_b) > 1)
    {
	    last_node_b = ft_lst_del_last(ptr_first_node_b);
    	ft_add_node_front(ptr_first_node_b, last_node_b);
        write(1, "rb\n", 3);
    }
}

void	ft_reverse_rotate_a(t_node **ptr_first_node_a)
{
	t_node	*first_node_a;

    if (*ptr_first_node_a != NULL && ft_size_lst(ptr_first_node_a) > 1)
    {
        first_node_a = ft_lst_del_first(ptr_first_node_a);
        ft_add_node(ptr_first_node_a, first_node_a);
        write(1, "rra\n", 4);
    }
}

void	ft_reverse_rotate_b(t_node **ptr_first_node_b)
{
	t_node	*first_node_b;

    if (*ptr_first_node_b != NULL && ft_size_lst(ptr_first_node_b) > 1)
    {
        first_node_b = ft_lst_del_first(ptr_first_node_b);
        ft_add_node(ptr_first_node_b, first_node_b);
        write(1, "rrb\n", 4);
    }
}

void ft_push_b(t_node **ptr_first_node_a, t_node **ptr_first_node_b)
{
    t_node  *last_node_a;

    if (ptr_first_node_a != NULL && ptr_first_node_b != NULL && ft_size_lst(ptr_first_node_a) > 0)
    {
        last_node_a = ft_lst_del_last(ptr_first_node_a);
        ft_add_node(ptr_first_node_b, last_node_a);
        write(1,"pb\n",3);
    }
}

void ft_push_a(t_node **ptr_first_node_a, t_node **ptr_first_node_b)
{
    t_node  *last_node_b;

    if (ptr_first_node_a != NULL && ptr_first_node_b != NULL && ft_size_lst(ptr_first_node_b) > 0)
    {
        last_node_b = ft_lst_del_last(ptr_first_node_b);
        ft_add_node(ptr_first_node_a, last_node_b);
        write(1,"pa\n",3);
    }
}

int ft_check_is_sorted(t_node **ptr_first_node)
{
    t_node  *current_node;

    current_node = *ptr_first_node;
    while (current_node->next != NULL)
    {
        if (current_node->value < (current_node->next)->value)
        {
            return (0);
        }
        current_node = current_node->next;
    }
    return (1);
}


void    ft_sort_two(t_node **ptr_first_node)
{
    t_node  *node1 = ft_last_node(ptr_first_node);
    t_node  *node0 = node1->previous;

    if (node0 != NULL && node1 != NULL)
    {
        if (node0->value < node1->value)
        {
            ft_swap_a(ptr_first_node);
        }
    }
}

void    ft_sort_three(t_node **ptr_first_node_a)
{
    t_node  *bottom;
    t_node  *mid;
    t_node  *top;

    top = ft_last_node(ptr_first_node_a);
    mid = top->previous;
    bottom = mid->previous;

    if (top != NULL && mid != NULL && bottom != NULL)
    {
        
        if (top->value > mid->value       //2 1 3
            && mid->value < bottom->value 
            && bottom->value > top->value)
        {
            ft_swap_a(ptr_first_node_a);
        }
        if (top->value > mid->value        //T=3 M=1 B=2
            && mid->value < bottom->value 
            && bottom->value < top->value)
        {
            ft_rotate_a(ptr_first_node_a);
        }
        if (top->value < mid->value
            && mid->value > bottom->value
            && bottom->value < top->value) //T=2 M=3 B=1
        {
            ft_reverse_rotate_a(ptr_first_node_a);
        }
        if (top->value > mid->value    //T=3 M=2 B=1
            && mid->value > bottom->value
            && bottom->value < top->value)
        {
            ft_swap_a(ptr_first_node_a);
            ft_reverse_rotate_a(ptr_first_node_a);
        }
        if (top->value < mid->value    //T=1 M=3 B=2
            && mid->value > bottom->value
            && bottom->value > top->value)
        {
            ft_swap_a(ptr_first_node_a);
            ft_rotate_a(ptr_first_node_a);
        }
    }
}

void    ft_sort_four(t_node **ptr_first_node_a, t_node **ptr_first_node_b)
{
    t_node *node_to_insert;

    if (ft_check_is_sorted(ptr_first_node_a) == 0)
    {    
        ft_push_b(ptr_first_node_a, ptr_first_node_b);
        ft_sort_three(ptr_first_node_a);
        node_to_insert = ft_last_node(ptr_first_node_b);

        if (node_to_insert->ind < ft_last_node(ptr_first_node_a)->ind)
        {
            ft_push_a(ptr_first_node_a, ptr_first_node_b);
        }
        else if (node_to_insert->ind > ft_last_node(ptr_first_node_a)->ind
                && node_to_insert->ind < ((ft_last_node(ptr_first_node_a))->previous)->ind)
        {   
            ft_rotate_a(ptr_first_node_a);
            ft_push_a(ptr_first_node_a, ptr_first_node_b);
            ft_reverse_rotate_a(ptr_first_node_a);
        }
        else if (node_to_insert->ind < (*ptr_first_node_a)->ind
                && node_to_insert->ind > ((*ptr_first_node_a)->next)->ind)
        {
            ft_reverse_rotate_a(ptr_first_node_a);
            ft_push_a(ptr_first_node_a, ptr_first_node_b);
            ft_rotate_a(ptr_first_node_a);
            ft_rotate_a(ptr_first_node_a);
        }
        else
        {
            ft_push_a(ptr_first_node_a, ptr_first_node_b);
            ft_rotate_a(ptr_first_node_a);
        }
    }
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	c;
	int	check;

	check = 0;
	while (check < size)
	{
		i = 0;
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				c = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = c;
			}	
			i++;
		}
		check++;
	}
}

void    ft_set_index_lst(t_node **ptr_first_node, int *tab_int, int tablen)
{
    int i;
    t_node  *current_node;

    i = 0;
    current_node = *ptr_first_node;
    while (i < tablen)
    {
        current_node = *ptr_first_node;
        while (current_node != NULL)
        {
            if (current_node->value == tab_int[i])
            {
                current_node->ind = (i + 1);
            }
            current_node = current_node->next;
        }
        i++;
    }
}

void    ft_sort_five(t_node **ptr_first_node_a, t_node **ptr_first_node_b)
{
    int pos_5;
    t_node *current_node;
    (void) ptr_first_node_b;

    pos_5 = 0;
    current_node = *ptr_first_node_a;
    if (ft_check_is_sorted(ptr_first_node_a) == 0)
    {
        while (current_node->ind != 5)
        {
            pos_5++;
            current_node = current_node->next;
        }
        pos_5 = 4 - pos_5;
        if (pos_5 <= 2)
        {
            while (pos_5 > 0)
            {
                ft_rotate_a(ptr_first_node_a);
                pos_5--;
            }
            ft_push_b(ptr_first_node_a, ptr_first_node_b);
            ft_sort_four(ptr_first_node_a, ptr_first_node_b);
            ft_push_a(ptr_first_node_a, ptr_first_node_b);
            ft_rotate_a(ptr_first_node_a);
        }
        else
        {
            pos_5 = 5 - pos_5;
            while (pos_5 > 0)
            {
                ft_reverse_rotate_a(ptr_first_node_a);
                pos_5--;
            }
            ft_push_b(ptr_first_node_a, ptr_first_node_b);
            ft_sort_four(ptr_first_node_a, ptr_first_node_b);
            ft_push_a(ptr_first_node_a, ptr_first_node_b);
            ft_rotate_a(ptr_first_node_a);
        }
    }
}

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