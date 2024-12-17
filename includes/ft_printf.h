/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:14:43 by stakada           #+#    #+#             */
/*   Updated: 2024/12/17 13:38:19 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

int ft_printf(const char *fmt, ...);
int	ft_vdprintf(int fd, const char *fmt, va_list ap);
int	dispatcher(int fd, char cspec, va_list ap);
int	ft_putchar(int fd, int c);
int	ft_puts(int fd, char *s);
int	ft_putdec(int fd, int num);
int ft_putudec(int fd, unsigned int num);
int ft_puthex_low(int fd, unsigned int num);
int ft_puthex_up(int fd, unsigned int num);
int	ft_putptr(int fd, unsigned long long ptr);
int ft_putnbr_base(int fd, unsigned long long num, char *base);

#endif