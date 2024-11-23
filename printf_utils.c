/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:34:52 by azmakhlo          #+#    #+#             */
/*   Updated: 2024/11/23 18:40:28 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putuhex(unsigned int c, int *count)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (c >= 16)
		ft_putuhex(c / 16, count);
	*count += write(1, &hex[c % 16], 1);
}

void	ft_puttnbr(int x, int *count)
{
	if (x == -2147483648)
	{
		ft_puttstr("-2147483648", count);
		return ;
	}
	if (x < 0)
	{
		ft_puttchar('-', count);
		x = -x;
	}
	if (x > 9)
		ft_puttnbr(x / 10, count);
	ft_puttchar(x % 10 + '0', count);
}

void	ft_putunbr(unsigned int x, int *count)
{
	if (x > 9)
		ft_putunbr(x / 10, count);
	ft_puttchar(x % 10 + '0', count);
}
