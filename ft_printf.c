/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:36:05 by azmakhlo          #+#    #+#             */
/*   Updated: 2024/11/23 18:40:05 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check(char l, va_list r, int *count)
{
	void	*v;

	if (l == 'c')
		ft_puttchar(va_arg(r, int), count);
	else if (l == 's')
		ft_puttstr(va_arg(r, char *), count);
	else if (l == 'i' || l == 'd')
		ft_puttnbr(va_arg(r, int), count);
	else if (l == 'x')
		ft_puthex(va_arg(r, unsigned int), count);
	else if (l == 'X')
		ft_putuhex(va_arg(r, unsigned int), count);
	else if (l == 'u')
		ft_putunbr(va_arg(r, unsigned int), count);
	else if (l == 'p')
	{
		v = va_arg(r, void *);
		*count += write(1, "0x", 2);
		ft_puthexx((unsigned long)v, count);
	}
	else
		ft_puttchar(l, count);
	return (*count);
}

int	ft_printf(const char *w, ...)
{
	va_list	r;
	int		i;
	int		count;

	va_start(r, w);
	i = -1;
	count = 0;
	count = write(1, "", 0);
	if (count == -1)
		return (-1);
	while (w[++i])
	{
		if (w[i] == '%' )
		{
			if (w[i + 1] != '\0')
			{
				check(w[i + 1], r, &count);
				i++;
			}
		}
		else
			count += write(1, &w[i], 1);
	}
	va_end(r);
	return (count);
}
