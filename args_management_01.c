/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_management_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:05:30 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/03 12:01:32 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_number(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
	{
		return (0);
	}
	if ((str[i] == '+' && ft_isdigit(str[i + 1]) == 1)
		|| (str[i] == '-' && ft_isdigit(str[i + 1]) == 1))
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

int	ft_check_args_number(char **tab_char, int tablen)
{
	int	i;

	i = 0;
	while (i < tablen)
	{
		if (ft_check_number(tab_char[i]) == 0)
		{
			write(2, "Error\n", 6);
			ft_free_tab_char(tab_char, tablen);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_args_int(char **tab_char, long *tab_long, int tablen)
{
	int	i;

	i = 0;
	while (i < tablen)
	{
		if (tab_long[i] > INT_MAX || tab_long[i] < INT_MIN)
		{
			ft_free_tab_char(tab_char, tablen);
			free(tab_long);
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_args_double(char **tab_char, long *tab_long, int tablen)
{
	int	i;
	int	j;

	i = 0;
	while (i < tablen)
	{
		j = i + 1;
		while (j < tablen)
		{
			if (tab_long[i] == tab_long[j])
			{
				write(2, "Error\n", 6);
				ft_free_tab_char(tab_char, tablen);
				free(tab_long);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_int_double(char **tab_char, long *tab_long, int tablen)
{
	if (ft_check_args_int(tab_char, tab_long, tablen) == 0)
	{
		return (0);
	}
	if (ft_check_args_double(tab_char, tab_long, tablen) == 0)
	{
		return (0);
	}
	return (1);
}
