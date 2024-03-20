/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:03:25 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/20 13:34:20 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	ft_print(char c)
{
	write(1, &c, 1);
	return (1);
}

static int ft_nbrlen(long int i)
{
	int len;

	len = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i *= -1;
		len++;
	}
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(long int i)
{
	int len;

	len = ft_nbrlen(i);
	if (i < 0)
	{
		ft_print('-');
		i = i * (-1);
	}
	if (i < 10)
	{
		ft_print(i + '0');
	}
	else
	{
		ft_putnbr(i / 10);
		ft_print(i % 10 + '0');
	}
	return (len);
}

// int main(void)
// {
// 	int i = -10;
// 	printf("%d\n", ft_putnbr(i));
// }