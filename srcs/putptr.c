/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:16:36 by stakada           #+#    #+#             */
/*   Updated: 2024/12/17 14:22:04 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(int fd, unsigned long long ptr)
{
	int	len;
	int	w_ret;

	len = 0;
	if (ptr == 0)
	{
		return (ft_puts(fd, "(nil)"));
	}
	w_ret = ft_puts(fd, "0x");
	if (w_ret < 0)
		return (-1);
	len += w_ret;
	w_ret = ft_putnbr_base(fd, ptr, "0123456789abcdef");
	if (w_ret < 0)
		return (-1);
	len += w_ret;
	return (len);
}
