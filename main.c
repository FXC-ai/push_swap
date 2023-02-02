/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:19:41 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/02 23:08:36 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    char    **tab_char;
    long    *tab_long;
    int     tablen;
    int     *tab_int;

    tab_int = NULL;
    tablen = argc - 1;
    if (argc == 1)
        return (0);
    tab_char = ft_create_tab_char(argc, argv);
    tablen = ft_size_table(tab_char);
    if (tablen == 0)
    {
        free(tab_char);
        return (0);
    }
    if (ft_check_args_number(tab_char, tablen) == 0)
        return (0);
    tab_long = ft_create_tab_long(tab_char, tablen);
    if (ft_check_int_double(tab_char, tab_long, tablen) == 0)
        return (0);
    tab_int = ft_convert_longtoint(tab_long, tablen);
    ft_free_tab_char(tab_char, tablen);
    ft_launch_algo(tab_int, tablen);
    return (0);
}
