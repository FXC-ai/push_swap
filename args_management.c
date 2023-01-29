/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:16:14 by fcoindre          #+#    #+#             */
/*   Updated: 2023/01/29 18:20:52 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int ft_check_number(char *str)
{
    int i;

    i = 0;
    if (ft_strlen(str) == 0)
    {
        return (0);
    }
    if ((str[i] == '+' && ft_isdigit(str[i+1]) == 1) || (str[i] == '-' && ft_isdigit(str[i+1]) == 1))
    {
        i++;
    }
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]) == 0)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

int ft_check_args_number(char **tab_char, int tablen)
{
	int i;

	i = 0;
	while (i < tablen)
	{
		if (ft_check_number(tab_char[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

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

int ft_size_table(char **tab_char)
{
    int i;
    i = 0;
    while (tab_char[i] != NULL)
        i++;
    return (i);
}

long  *ft_create_tab_long(char **tab_char, int tablen)
{
	int i;
	long *tab_long;

	tab_long = (long *) malloc(sizeof(long) * tablen);
	if (tab_long == NULL)
		return (NULL);
	i = 0;
	while (i < tablen)
	{
		tab_long[i] = ft_atoi(tab_char[i]);
		i++;
	}
	return  tab_long;
}

int ft_check_args_int(long *tab_long, int tablen)
{
	int i;

	i = 0;
	while (i < tablen)
	{
		if (tab_long[i] > INT_MAX || tab_long[i] < INT_MIN)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int ft_check_args_double(long *tab_long, int tablen)
{
	int i;
	int j;

	i = 0;
	while (i < tablen)
	{
		j = i + 1;
		while (j < tablen)
		{
			if (tab_long[i] == tab_long[j])
			{
				return (0);
			}
			j++;
		}   
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
    char    **tab_char;
    long    *tab_long;
    int     tablen;
    char    *args;

    args = NULL;
    tablen = argc - 1;

    if (argc == 1)
        return (0);
    else if (argc == 2)
        args = ft_strdup(argv[1]);
    else
        args = ft_join_args(argc , argv);
    
    tab_char = ft_split(args, ' ');
    free(args);

    tablen = ft_size_table(tab_char);

    if (tablen == 0)
    {
        free(tab_char);
        return (0);
    }
    
    if (ft_check_args_number(tab_char, tablen) == 0)
    {
        write(2,"Error\n",6);
        ft_free_tab_char(tab_char, tablen);
        return (0);
    }

    tab_long = ft_create_tab_long(tab_char, tablen);

    if (ft_check_args_int(tab_long, tablen) == 0)
    {
        write(2,"Error\n",6);
        ft_free_tab_char(tab_char, tablen);
        free(tab_long);
        return (0);
    }
    
    if (ft_check_args_double(tab_long, tablen) == 0)
    {
        write(2,"Error\n",6);
        ft_free_tab_char(tab_char, tablen);
        free(tab_long);
        return (0);
    }
    
    free(tab_long);
    ft_free_tab_char(tab_char, tablen);

    return (0);
}
