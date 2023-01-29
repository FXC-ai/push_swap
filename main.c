/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:19:41 by fcoindre          #+#    #+#             */
/*   Updated: 2023/01/29 18:39:20 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    char    **tab_char;
    long    *tab_long;
    int     tablen;
    char    *args;
    int    *tab_int;

    tab_int = NULL;
    args = NULL;
    tablen = argc - 1;

    if (argc == 1)
    {
        return (0);
    }
    else if (argc == 2)
    {
        args = ft_strdup(argv[1]);
    }
    else
    {
        args = ft_join_args(argc , argv);
    }
    
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
    
    tab_int = ft_convert_longtoint(tab_long, tablen);
    ft_free_tab_char(tab_char, tablen);


    free(tab_int);

    return (0);
}