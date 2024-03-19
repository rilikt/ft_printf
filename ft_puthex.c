/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:34:03 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/19 16:33:01 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

static int ft_hexlen(long int hex)
{
	int len;
	int j;

	j = 1;
	len = 0;
	while (hex > 0)
	{	
		j = hex % 16;
		hex /= 16;
		len++;
	}
	return (len);
}

void ft_puthex(long int hex)
{
	int len;
	char *arr;
	int i;

	i = 1;
	len = ft_hexlen(hex);
	arr = (char *)malloc(len+1 * sizeof(char));
	arr[len] = '\0';
	len -= 1;
	while (len >= 0)
	{
		i = hex % 16;
		hex /= 16;
		if (i < 10)
			arr[len] = i + '0';
		else if (i >= 10 && i <= 15)
			arr[len] = i + 87;
		len--;
	}
	ft_putstr(arr);
	free (arr);
}

void ft_putheX(long int hex)
{
	int len;
	char *arr;
	int i;

	i = 1;
	len = ft_hexlen(hex);
	arr = (char *)malloc(len+1 * sizeof(char));
	arr[len] = '\0';
	len -= 1;
	while (len >= 0)
	{
		i = hex % 16;
		hex /= 16;
		if (i < 10)
			arr[len] = i + '0';
		else if (i >= 10 && i <= 15)
			arr[len] = i + 55;
		len--;
	}
	ft_putstr(arr);
	free (arr);
}