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