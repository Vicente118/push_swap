/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:25:40 by vdarras           #+#    #+#             */
/*   Updated: 2024/04/22 14:11:47 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

// COEUR DU PROGRAMME
int	ft_printf(const char *format, ...);
int	ft_find_format(va_list ap, char c);
int	check_next_char(char *str);

// UTILS
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_print_hexa_min(unsigned int nb);
int	ft_print_hexa_maj(unsigned int nb);
int	ft_putnbr(int nb);
int	ft_unsigned_putnbr(unsigned int nb);
int	ft_print_hexa_min_long(unsigned long nb);

#endif