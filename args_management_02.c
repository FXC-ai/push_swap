/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:16:14 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/02 20:13:28 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int *ft_convert_longtoint(long *tab_long, int tablen)
{
    int i;
    int *tab_int;

    tab_int = malloc(sizeof(int) * tablen);
    if (tab_int == NULL)
    {
        return (NULL);
    }
    i = 0;
    while (i < tablen)
    {
        tab_int[i] = (int) tab_long[i];
        i++;
    }
    free(tab_long);
    return (tab_int);
}