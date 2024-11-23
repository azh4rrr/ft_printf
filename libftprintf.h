/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:05:09 by azmakhlo          #+#    #+#             */
/*   Updated: 2024/11/23 18:43:06 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *w, ...);
void	ft_puttstr(char *s, int *count);
void	ft_puttchar(char c, int *count);
void	ft_puthex(unsigned int c, int *count);
void	ft_puthexx(unsigned long c, int *count);
void	ft_putuhex(unsigned int c, int *count);
void	ft_puttnbr(int x, int *count);
void	ft_putunbr(unsigned int x, int *count);

#endif