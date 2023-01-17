#include "push_swap.h"
#include <stdio.h>



t_node	*ft_new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
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

void	ft_display_node(t_node	*node)
{
	ft_printf("[%p] {value = %d | previous = %p |next = %p}\n", node, node->value, node->previous, node->next);
}

t_node	*ft_last_node(t_node **first_node)
{
	t_node *current_node;

	current_node = *first_node;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	return current_node;
}

void	ft_add_node(t_node **first_node, t_node *new_node)
{
	t_node	*last_node;

	last_node = ft_last_node(first_node);
	if (first_node != NULL)
	{
		if (*first_node == NULL)
			*first_node = new_node;
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

void	ft_destruct_lst(t_node **first_node)
{
	t_node	*current_node;
	t_node	*next_node;

	next_node = NULL;
	current_node = *first_node;
	while (current_node->next != NULL)
	{
		next_node = current_node->next;
		ft_destruct_node(current_node);
		current_node = next_node;
		next_node = NULL;
	}
	free(current_node);
}

void	ft_display_lst(t_node **first_node)
{
	t_node	*current_node;
	int		count;

	current_node = *first_node;
	count = 0;
	while (current_node->next != NULL)
	{
		ft_printf("Index = %d : ", count);
		ft_display_node(current_node);
		current_node = current_node->next;
		count++;
		//sleep(1);
	}
	ft_printf("Index = %d : ", count);
	ft_display_node(current_node);
}

void	ft_swap(t_node **first_node)
{

	t_node	*last_node;
	t_node	*penultimate_node;
	t_node	*second_penultimate_node;

	t_node	*previous;

	last_node = ft_last_node(first_node);
	penultimate_node = last_node->previous;
	second_penultimate_node = penultimate_node->previous;

	previous = penultimate_node->previous;
	last_node->next = penultimate_node;

	penultimate_node->previous = last_node;
	penultimate_node->next = NULL;
	last_node->previous = previous;

	second_penultimate_node->next = last_node;

}

void	ft_rotate(t_node **ptr_first_node)
{
	t_node	*last_node;
	t_node	*penultimate_node;
	t_node	*first_node;

	last_node = ft_last_node(ptr_first_node);
	penultimate_node = last_node->previous;
	first_node = *ptr_first_node;

	penultimate_node->next = NULL;
	last_node->previous = NULL;
	ft_add_node_front(ptr_first_node, last_node);
}


void	ft_reverse_rotate(t_node **ptr_first_node)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*last_node;

	first_node = *ptr_first_node;
	second_node = first_node->next;
	last_node = ft_last_node(ptr_first_node);

	ft_add_node(ptr_first_node, first_node);
	first_node->next = NULL;
	second_node->previous = NULL;
	*ptr_first_node = second_node;
}

int	main(void)
{	
	t_node *node0 = ft_new_node(12);
	t_node *node1 = ft_new_node(42);
    int tab[9] = {78,42,24, 87, 44, 120, 950, 1001, -83};
    t_node *node00;

    ft_add_node(&node0, node1);

    node00 = ft_create_lst(tab, 9);

    



    printf("\n\n----------------DISPLAY BEGIN----------------\n\n");

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


    printf("\n\n----------------DISPLAY   END----------------\n\n");

    ft_destruct_lst(&node00);
    ft_destruct_node(node0);
    ft_destruct_node(node1);

	return 0;
}