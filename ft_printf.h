/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:32:40 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/20 13:23:35 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

extern int ft_printf(const char *, ...);
extern int	ft_putnbr(long int i);
extern int	ft_putunbr(unsigned int i);
extern void ft_puthex(long long int hex);
extern void ft_putheX(long long int hex);
extern int ft_putstr(const char *str);
extern void ft_putchar(const char c);
extern int ft_countarg(const char* str);
extern int ft_checkset(const char *str);
extern void ft_putptr(void *ptr);



#endif