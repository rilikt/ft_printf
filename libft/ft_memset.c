/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:14:24 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/16 12:58:22 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	v;

	p = (unsigned char *)dest;
	v = (unsigned char)c;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	str[] = "This is an example string";

// 	printf("%s\n", str);
// 	ft_memset(str, '*', 7);
// 	printf("%s\n", str);
// 	return (0);
// }
