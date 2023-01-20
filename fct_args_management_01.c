/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_args_management_01.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:18:04 by fcoindre          #+#    #+#             */
/*   Updated: 2023/01/20 16:32:35 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
