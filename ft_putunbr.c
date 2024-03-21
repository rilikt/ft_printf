/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:03:25 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/21 14:39:52 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print(char c)
{
	write(1, &c, 1);
}

static int	ft_nbrlen(unsigned int i)
{
	int	len;

	len = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

int	ft_putunbr(unsigned int i)
{
	int	len;

	len = ft_nbrlen(i);
	if (i < 10)
	{
		ft_print(i + '0');
	}
	else
	{
		ft_putunbr(i / 10);
		ft_print(i % 10 + '0');
	}
	return (len);
}

// int main(void)
// {
// 	int i = -10;
// 	printf("%d\n", ft_putunbr(i));
// }