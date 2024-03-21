/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:34:03 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/21 14:39:36 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int hex)
{
	int	len;
	int	j;

	j = 1;
	len = 0;
	if (hex == 0)
		return (1);
	while (hex > 0)
	{
		j = hex % 16;
		hex /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex(long long int hex)
{
	int				len;
	char			*arr;
	int				i;
	unsigned int	uhex;

	i = 1;
	uhex = (unsigned int)hex;
	len = ft_hexlen(uhex);
	arr = (char *)malloc(len + 1 * sizeof(char));
	arr[len] = '\0';
	len -= 1;
	while (len >= 0)
	{
		i = uhex % 16;
		uhex /= 16;
		if (i < 10)
			arr[len] = i + '0';
		else if (i >= 10 && i <= 15)
			arr[len] = i + 87;
		len--;
	}
	len = ft_putstr(arr);
	free(arr);
	return (len);
}

int	ft_putupperhex(long long int hex)
{
	int				len;
	char			*arr;
	int				i;
	unsigned int	uhex;

	i = 1;
	uhex = (unsigned int)hex;
	len = ft_hexlen(uhex);
	arr = (char *)malloc(len + 1 * sizeof(char));
	arr[len] = '\0';
	len -= 1;
	while (len >= 0)
	{
		i = uhex % 16;
		uhex /= 16;
		if (i < 10)
			arr[len] = i + '0';
		else if (i >= 10 && i <= 15)
			arr[len] = i + 55;
		len--;
	}
	len = ft_putstr(arr);
	free(arr);
	return (len);
}

// int main(void)
// {
// 	int i = -10;
// 	printf("Return Value: %d\n", ft_puthex(i));
// 	printf("Return Value: %d\n", printf("%x", i));

// }