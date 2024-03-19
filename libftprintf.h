/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:32:40 by timschmi          #+#    #+#             */
/*   Updated: 2024/03/19 17:12:39 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

extern int ft_printf(const char *, ...);
extern void	ft_putnbr(long int i);
extern void	ft_putunbr(unsigned int i);
extern void ft_puthex(long int hex);
extern void ft_putheX(long int hex);
extern void ft_putstr(const char *str);
extern void ft_putchar(const char c);
extern int ft_countarg(const char* str);
extern int ft_checkset(const char *str);
extern void ft_putptr(void *ptr);



#endif