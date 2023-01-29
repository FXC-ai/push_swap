#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	int				ind;
	struct s_node	*previous;
	struct s_node	*next;
} t_node;

//fct_args_management
int		ft_check_number(char *str);
int		ft_check_args_number(char **tab_char, int tablen);
char    *ft_join_args(int argc, char *argv[]);
void	ft_free_tab_char(char **tab, int tablen);
int		ft_size_table(char **tab_char);
long 	*ft_create_tab_long(char **tab_char, int tablen);
int		ft_check_args_int(long *tab_long, int tablen);
int		ft_check_args_double(long *tab_long, int tablen);

#endif