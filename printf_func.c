/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:59:43 by azmakhlo          #+#    #+#             */
/*   Updated: 2024/11/23 18:03:18 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puttstr(char *s, int *count)
{
	if (!s)
		*count += write(1, "(null)", 6);
	else
	{
		while (*s)
		{
			ft_puttchar(*s, count);
			s++;
		}
	}
}

void	ft_puttchar(char c, int *count)
{
	*count += write(1, &c, 1);
}

void	ft_puthex(unsigned int c, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c >= 16)
		ft_puthex(c / 16, count);
	*count += write(1, &hex[c % 16], 1);
}

void	ft_puthexx(unsigned long c, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c >= 16)
		ft_puthexx(c / 16, count);
	*count += write(1, &hex[c % 16], 1);
}
