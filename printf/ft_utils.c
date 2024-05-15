/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:25:55 by vdarras           #+#    #+#             */
/*   Updated: 2024/04/22 13:17:49 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		i++;
	}
	return (i);
}

int	ft_print_hexa_min(unsigned int nb)
{
	int		result;
	char	*base;

	result = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		result += ft_print_hexa_min(nb / 16);
		result += ft_print_hexa_min(nb % 16);
	}
	else
		result += ft_putchar(base[nb % 16]);
	return (result);
}

int	ft_print_hexa_maj(unsigned int nb)
{
	int		result;
	char	*base;

	result = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		result += ft_print_hexa_maj(nb / 16);
		result += ft_print_hexa_maj(nb % 16);
	}
	else
		result += ft_putchar(base[nb % 16]);
	return (result);
}

int	ft_putnbr(int nb)
{
	int	result;

	result = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		result += write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		result += ft_putnbr(nb / 10);
		result += ft_putnbr(nb % 10);
	}
	else
		result += ft_putchar(nb + 48);
	return (result);
}
