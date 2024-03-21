/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:02:44 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/21 13:30:30 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_hexlen(unsigned long int hex)
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

static int	ft_putptrhex(long long int hex)
{
	int		len;
	char	*arr;
	int		i;
	unsigned long int uhex;

	i = 1;
	uhex = (unsigned long int)hex;
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

int	ft_putptr(void *ptr)
{
	unsigned long int	i;
	int len;

	i = (unsigned long int)ptr;
	write(1, "0x", 2);
	len = ft_putptrhex(i);
	return (len + 2);
}

// int main(void)
// {
// 	int i;

// 	i = 0;
// 	printf("%d\n", ft_putptr((void *)ULONG_MAX));
// }