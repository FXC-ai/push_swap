/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_args_management_00.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:35:36 by fcoindre          #+#    #+#             */
/*   Updated: 2023/01/26 15:50:32 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_number(char *arg)
{
	int i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
	{
		i = 1;
	}
	if (ft_isdigit(arg[i]) == 0)
	{
		return (0);
	}
	while (arg[i] != '\0')
	{   
		if (ft_isdigit(arg[i]) == 0)
		{
			return (0);
		}   
		i++;
	}
	return (1);
}

int ft_is_int(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
	{
		return (0);
	}
	return (1);
}

int ft_tablen(char **tab)
{
	int count;

	count = 0;
	while (tab[count] != NULL)
	{
		count++;
	}
	return (count);
}

int ft_check_args_int(int argc, long *args)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (ft_is_int(args[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int ft_check_args_number(int argc, char **args)
{
	int i;
	char *test;

	i = 0;
	while (i < argc)
	{
		test = args[i];
		if (ft_is_number(args[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int ft_check_double(int argc, long *args)
{
	int i;
	int j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (args[i] == args[j])
			{
				return (0);
			}
			j++;
		}   
		i++;
	}
	return (1);
}
static void	ft_free_tabs(char **tab, int tablen, int argc)
{
	int	i;

	i = 0;
	if (argc == 1)
	{
		while (i <= tablen)
		{
			free(tab[i]);
			i++;
		}
	}
	free(tab);
}

static long  *ft_create_tab_long(int argc, char **tab)
{
	int i;
	long *tab_long;

	tab_long = (long *) malloc(sizeof(long) * argc);
	if (tab_long == NULL)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		tab_long[i] = ft_atoi(tab[i]);
		i++;
	}
	return  tab_long;
}

static char **ft_set_args(int argc, char **arg)
{
	char    **tab;
	int     i;

	tab = (char **) malloc(sizeof(char *) * argc);
	i = 0;
	while (i < argc)
	{
		tab[i] = arg[i + 1];
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

static int  ft_check_args(int tablen, char **tab_char, long **tab_long, int argc)
{
	if (ft_check_args_number(tablen, tab_char) == 0)
	{
		ft_free_tabs(tab_char, tablen, argc);
		return (1);
	}
	else
	{
		*tab_long = ft_create_tab_long(tablen, tab_char);		
		if (ft_check_args_int(tablen, *tab_long) == 0)
		{
			ft_free_tabs(tab_char, tablen, argc);
			free(*tab_long);
			return (1);
		}
		if (ft_check_double(tablen, *tab_long) == 0)
		{
			ft_free_tabs(tab_char, tablen, argc);
			free(*tab_long);
			return (1);
		}
	}
	ft_free_tabs(tab_char, tablen, argc);
	return (0);
}

long    *ft_args_management(int argc, char *argv[], int *args_valid, int *tablen)
{
	char    **tab_char;
	long    *tab_long;

	tab_long = NULL;
	if ((argc - 1) == 0)
		*args_valid = -1;
	else if ((argc - 1) == 1)
	{
		tab_char = ft_split(argv[1], ' ');
		*tablen = ft_tablen(tab_char);
		/*if (tablen == 0)
		{
			*args_valid = -1;
			return tab_long;
		}*/
		
		*args_valid = ft_check_args(*tablen, tab_char, &tab_long, (argc - 1));
	}
	else
	{
		*tablen = (argc - 1);
		tab_char = ft_set_args(*tablen, argv);
		*args_valid = ft_check_args(*tablen, tab_char, &tab_long, (argc - 1));
	}
	//if (*args_valid == 1)
	//	write(2, "Error\n", 6);
	return tab_long;
}
/*
int main(int argc, char *argv[])
{

    long    *tab_long;
    int     args_valid;
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
}*/