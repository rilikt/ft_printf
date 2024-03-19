/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:03:25 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/19 15:15:27 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

static void	ft_print(char c)
{
	write(1, &c, 1);
}

void	ft_putunbr(unsigned int i)
{
	// if (i < 0)
	// {
	// 	ft_print('-');
	// 	i = i * (-1);
	// }
	if (i < 10)
	{
		ft_print(i + '0');
	}
	else
	{
		ft_putnbr(i / 10);
		ft_print(i % 10 + '0');
	}
}
