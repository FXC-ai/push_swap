#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include "leacks_cheker_ex.c"

t_node	*ft_nodenew(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

t_node	*ft_lastnode(t_node **first_node)
{

	t_node *current_node;

	current_node = *first_node;

	while (current_node->next != NULL)
		current_node = current_node->next;

	//ft_printf("Voici le pointeur du dernier maillon : %p\n", current_node);

	return current_node;

}

// ATTENTION il faudrait verifier que *
void	ft_addnode(t_node **first_node, t_node *new_node)
{
	t_node	*last_node;

	last_node = ft_lastnode(first_node);
	if (first_node != NULL)
	{
		if (*first_node == NULL)
			*first_node = new_node;
		if (last_node != NULL)
			last_node->next = new_node;
	}
}


t_node	*ft_create_stack(int *tab, int size_tab)
{
	t_node	*current_node;
	t_node	*first_node;

	size_tab--;
	first_node = ft_nodenew(tab[size_tab]);
	size_tab--;
	while (size_tab > 0)
	{
		current_node = ft_nodenew(tab[size_tab]);
		ft_addnode(&first_node, current_node);
		size_tab--;
	}
	return	(first_node);
}

void	*ft_destruct_stack(t_node **first_node)
{
	t_node	*current_node;
	t_node	*next_node;

	next_node = NULL;
	current_node = *first_node;
	while (current_node->next != NULL)
	{
		next_node = current_node->next;
		current_node->next = NULL;
		free(current_node);
		current_node = next_node;
		next_node = NULL;
	}
	free(current_node);
	return current_node;
}


void	ft_display_lst(t_node **first_node)
{
	t_node	*current_node;
	int		count;

	current_node = *first_node;
	count = 0;
	while (current_node->next != NULL)
	{
		ft_printf("node %d : {value = %d | next = %p}\n", count, current_node->value, current_node->next);
		current_node = current_node->next;
		count++;
	}
	ft_printf("node %d : {value = %d | next = %p}\n", count, current_node->value, current_node->next);
}

/*
void	ft_swap(t_node **first_node)
{

	t_node	*last_node;
	t_node	

	last_node = ft_lastnode(first_node);



}*/

int	main()
{	

	int		tab[5] = {0,1,2,3,4};
	t_node	*node0 = ft_create_stack(tab, 5);

	ft_display_lst(&node0);



	ft_destruct_stack(&node0);


	check_leaks();
	return 0;
}



