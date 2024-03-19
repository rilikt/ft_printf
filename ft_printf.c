/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:39:04 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/19 16:37:21 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

static void ft_ident(const char c, va_list args)
{
	if (c == 'd')
		ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		ft_putunbr(va_arg(args, unsigned int));
	else if (c == 's')
		ft_putstr(va_arg(args, char*));
	else if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 'x')
		ft_puthex(va_arg(args, int));
	else if (c == 'X')
		ft_putheX(va_arg(args, int));
	else if (c == '%')
		write(1, "%", 1);
}

static void ft_printcheck(const char *str, va_list args)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(ft_checkset(&str[i])) && str[i] != '%')
			write(1, &str[i], 1);
		if (ft_checkset(&str[i]))
		{
			ft_ident(str[i +1], args);
			i +=2;
		}
		else
			i++;
	}
}

int ft_printf(const char *str, ...)
{
	int n;

	n = ft_countarg(str);
	printf("Ammount of Args: %d\n", n);
	va_list args;
	va_start(args, str);

	ft_printcheck(str, args);
	return (0);
}

int main(void)
{	
	int i = -2147483648;
	int j = 777;
	int hex = 450;
	unsigned int u = 4294967295;
	char *str = "test";
	char c = 'A';
	ft_printf("Int (d): %d\nInt (i): %i\nUnsigned int (u): %u\nHex (x): %x\nHex (X): %X\nString (s): %s\nChar (c): %c\nPercent (%%): %%\n", i, j, u, hex, hex, str, c);
	printf("Int (d): %d\nInt (i): %i\nUnsigned int (u): %u\nHex (x): %x\nHex (X): %X\nString (s): %s\nChar (c): %c\nPercent (%%): %%\n", i, j, u, hex, hex, str, c);
}