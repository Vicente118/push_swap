/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:25:56 by vdarras           #+#    #+#             */
/*   Updated: 2024/04/22 16:07:43 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int nb)
{
	unsigned int	result;

	result = 0;
	if (nb > 9)
	{
		result += ft_putnbr(nb / 10);
		result += ft_putnbr(nb % 10);
	}
	else
		result += ft_putchar(nb + 48);
	return (result);
}

int	ft_print_hexa_min_long(unsigned long nb)
{
	int		result;
	char	*base;

	result = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		result += ft_print_hexa_min_long(nb / 16);
		result += ft_print_hexa_min_long(nb % 16);
	}
	else
		result += ft_putchar(base[nb % 16]);
	return (result);
}
