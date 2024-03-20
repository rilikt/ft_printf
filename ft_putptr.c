/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:02:44 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/20 13:09:42 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_putptr(void *ptr)
{
	unsigned long int	i;

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