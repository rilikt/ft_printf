/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:39:04 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/20 13:38:21 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <limits.h>

static int	ft_ident(const char c, va_list args)
{
	int len;

	len = 0;
	if (c == 'd')
		len = ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len = ft_putunbr(va_arg(args, unsigned int));
	else if (c == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (c == 'c')
	{
		ft_putchar(va_arg(args, int));
		len++;
	}
	else if (c == 'x')
		ft_puthex(va_arg(args, int));
	else if (c == 'X')
		ft_putheX(va_arg(args, int));
	else if (c == 'p')
		ft_putptr(va_arg(args, void *));
	else if (c == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

static int	ft_printcheck(const char *str, va_list args)
{
	int	i;
	int	count;
	int len;

	len = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		len = 0;
		if (!(ft_checkset(&str[i])) && str[i] != '%')
		{
			write(1, &str[i], 1);
			count++;
		}
		if (ft_checkset(&str[i]))
		{
			len = ft_ident(str[i + 1], args);
			i += 2;
		}
		else
			i++;
		count += len;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		n;
	int		count;
	va_list	args;

	// n = ft_countarg(str);
	va_start(args, str);
	count = ft_printcheck(str, args);
	// printf("%d\n", count + n);
	return (count);
}

int main(void)
{
	int i = -2147483648;
	int j = 777;
	int hex = 450;
	unsigned int u = 4294967295;
	char *str = "test";
	char c = 'A';
	
	int out = ft_printf("%s", str);
	printf("%d\n", out);


// 	ft_printf("Int (d): %d\nInt (i): %i\nUnsigned int (u): %u\nHex (x): %x\nHex (X): %X\nAdress (p): %p\nString (s): %s\nChar (c): %c\nPercent (%%): %%\n", i, j, u, hex, hex, (void *)&i, str, c);

//  	printf("Int (d): %d\nInt (i): %i\nUnsigned int (u): %u\nHex (x): %x\nHex (X): %X\nAdress (p): %p\nString (s): %s\nChar (c): %c\nPercent (%%): %%\n", i, j, u, hex, hex, (void *)&i, str, c);
}