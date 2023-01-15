#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include "leacks_cheker_ex.c"
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
/*
void	ft_add_node_front(t_node **first_node, t_node *new_node)
{
	(*first_node)->previous = new_node;
	new_node->next = *first_node;
	first_node = new_node;


}
*/


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

t_node	*ft_create_stack(int *tab, int size_tab)
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

void	ft_destruct_node(t_node *node)
{
	if (node != NULL)
	{
		node->previous = NULL;	
		node->next = NULL;
		free(node);
	}
}

void	ft_destruct_stack(t_node **first_node)
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

void	ft_display_node(t_node	*node)
{
	ft_printf("[%p] {value = %d | previous = %p |next = %p}\n", node, node->value, node->previous, node->next);
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


void	ft_reverse(t_node **ptr_first_node)
{
	t_node	*last_node;
	t_node	*penultimate_node;
	t_node	*first_node = *ptr_first_node;

	penultimate_node = last_node->previous;

	penultimate_node->next = NULL;
	last_node->previous = NULL;
	ft_add_node_front(ptr_first_node, last_node);
}

void	ft_reverse_reverse()
{

	
}

int	main(void)
{	

	int tab[3] = {445,58,73};
	t_node *node0 = ft_create_stack(tab, 3);

	ft_display_lst(&node0);

	ft_reverse(&node0);

	printf("\n\n");

	ft_display_lst(&node0);


	//check_leaks();
	return 0;
}



