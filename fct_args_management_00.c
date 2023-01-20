/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_args_management_00.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:35:36 by fcoindre          #+#    #+#             */
/*   Updated: 2023/01/20 16:27:11 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_number(char *arg)
{
	int i;

	i = 0;
	if (arg[0] == '-')
	{
		i = 1;
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
