/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:25:55 by stakada           #+#    #+#             */
/*   Updated: 2024/05/12 16:49:15 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_u_decimal_left(int num, t_spec specs)
{
	
}

void	put_u_decimal_right(int num, t_spec specs)
{
	
}

int	ft_printf_u(t_spec specs, va_list args)
{
	unsigned int u;
	int len;

	u = va_arg(args, unsigned int);
	len = 0;
	if (!(specs.flags & FLAG_HYPHEN || specs.flags & FLAG_ZERO || specs.flags == 0))
		return (-1);
	if (specs.flags & FLAG_HYPHEN)
		put_u_decimal_left(u, specs);
	else
		put_u_decimal_right(u, specs);
	return (len);
}