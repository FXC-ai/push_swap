#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*previous;
	struct s_node	*next;
} t_node;

#endif