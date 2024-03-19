/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:02:44 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/19 17:23:08 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

void ft_putptr(void *ptr)
{
	unsigned long int i;

	i = (unsigned long int)ptr;
	write(1, "0x", 2);
	ft_puthex(i);
}

// int main(void)
// {
// 	int i;

// 	i = 0;
// 	ft_putptr((void *)&i);
// }