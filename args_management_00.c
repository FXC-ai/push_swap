/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_management_00.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:00:37 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/02 20:09:06 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char    *ft_join_args(int argc, char *argv[])
{
    (void) argc;
    int i;
    char *result;
    char *temp;

    i = 1;
    result = ft_strdup(argv[1]);
    while (i < (argc - 1))
    {   
        temp = ft_strdup(result);
        free(result);
        result = ft_strjoin(temp, " ");
        free(temp);
        temp = ft_strdup(result);
        free(result);
        i++;
        result = ft_strjoin(temp, argv[i]);
        free(temp);
    }
    return (result);
}

char    **ft_create_tab_char(int argc, char *argv[])
{
    char    *args;
    char    **tab_char;

    if (argc == 2)
    {
        args = ft_strdup(argv[1]);
    }
    else
    {
        args = ft_join_args(argc , argv);
    }

    tab_char = ft_split(args, ' ');
    free(args);
    return (tab_char);
}

int ft_size_table(char **tab_char)
{
    int i;
    i = 0;
    while (tab_char[i] != NULL)
        i++;
    return (i);
}

void	ft_free_tab_char(char **tab, int tablen)
{
	int	i;

	i = 0;
	while (i <= tablen)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}