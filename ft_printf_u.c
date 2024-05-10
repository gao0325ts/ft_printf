/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:25:55 by stakada           #+#    #+#             */
/*   Updated: 2024/05/10 16:35:48 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_u_decimal_left(int num)
{
	
}

void	put_u_decimal_right(int num)
{
	
}

int	ft_printf_u(t_info info, va_list args)
{
	unsigned int u;
	int len;

	u = va_arg(args, unsigned int);
	len = 0;
	if (!(info.flags & FLAG_HYPHEN || info.flags & FLAG_ZERO || info.flags == 0))
		return (-1);
	if ()
		
	return (len);
}