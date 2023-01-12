/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:13:05 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/20 18:09:53 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(va_list args, int *ptr_c_count)
{
	int		int_to_print;
	char	*nbr_to_print_char;

	int_to_print = va_arg(args, int);
	ft_putnbr_fd(int_to_print, 1);
	nbr_to_print_char = ft_itoa(int_to_print);
	*ptr_c_count += ft_strlen(nbr_to_print_char);
	free(nbr_to_print_char);
}
