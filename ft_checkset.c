/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:35:06 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/20 13:08:53 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_checkset(const char *str)
{
	char *set = "cspdiuxX%";
	int i;
	int j;

	i = 0;
	j = 0;
	while (set[i])
	{
		if (str[j] == '%' && str[j + 1] == set[i])
			return (1);
		i++;
	}
	return (0);
}