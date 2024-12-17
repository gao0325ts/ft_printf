/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:15:39 by stakada           #+#    #+#             */
/*   Updated: 2024/12/17 13:55:36 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex_low(int fd, unsigned int num)
{
	int len;
	int w_ret;

	len = 0;
	// w_ret = ft_puts(fd, "0x");
	// if (w_ret < 0)
	// 	return (-1);
	// len += w_ret;
	w_ret = ft_putnbr_base(fd, (unsigned long long)num, "0123456789abcdef");
	if (w_ret < 0)
		return (-1);
	len += w_ret;
	return (len);
}

int ft_puthex_up(int fd, unsigned int num)
{
	int len;
	int w_ret;

	len = 0;
	// w_ret = ft_puts(fd, "0X");
	// if (w_ret < 0)
	// 	return (-1);
	// len += w_ret;
	w_ret = ft_putnbr_base(fd, (unsigned long long)num, "0123456789ABCDEF");
	if (w_ret < 0)
		return (-1);
	len += w_ret;
	return (len);
}
