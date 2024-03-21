/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:39:04 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/21 16:16:16 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ident(const char c, va_list args)
{
	int	len;

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
		len = ft_putchar(va_arg(args, int));
	else if (c == 'x')
		len = ft_puthex(va_arg(args, int));
	else if (c == 'X')
		len = ft_putupperhex(va_arg(args, int));
	else if (c == 'p')
		len = ft_putptr(va_arg(args, void *));
	else if (c == '%')
		len = ft_putchar('%');
	return (len);
}

static int	ft_printcheck(const char *str, va_list args)
{
	int	i;
	int	count;
	int	len;

	len = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		len = 0;
		if (!(ft_checkset(&str[i])) && str[i] != '%')
			len = write(1, &str[i], 1);
		if (ft_checkset(&str[i]) && len != -1)
		{
			len = ft_ident(str[i + 1], args);
			i += 2;
		}
		else
			i++;
		if (len == -1)
			return (-1);
		count += len;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	va_start(args, str);
	count = ft_printcheck(str, args);
	return (count);
}

// int main(void)
// {
// 	int i = ft_printf("\001\002\007\v\010\f\r\n");
// 	printf("\nReturn: %d\n", i);

// 	int j = printf("\001\002\007\v\010\f\r\n");
// 	printf("\nOG.Return: %d\n", j);
// }
