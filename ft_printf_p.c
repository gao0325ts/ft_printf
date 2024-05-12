/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:23:16 by stakada           #+#    #+#             */
/*   Updated: 2024/05/12 16:49:15 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_pointer_left(unsigned long long p, int width)
{
	int	len;

	len = 0;
	len += put_hexadecimal(p, 0);
	while (len++ < width)
		if (write(FD, " ", 1) < 0)
			return (-1);
	return (len);
}

int	put_pointer_right(unsigned long long p, int width)
{
	int	len;

	len = 1;
	while (p)
	{
		p = p / 16;
		len++;
	}
	while (len++ < width)
		if (write(FD, " ", 1) < 0)
			return (-1);
	put_hexadecimal(p, 1);
	return (len);
}

int	ft_printf_p(t_spec specs, va_list args)
{
	unsigned long long	p;
	int					len;

	p = va_arg(args, unsigned long long);
	len = 0;
	if (!(specs.flags == FLAG_HYPHEN || specs.flags == 0))
		return (-1);
	if (specs.flags & PRECISION_FLAG)
		return (-1);
	if (specs.flags == FLAG_HYPHEN)
		len = put_pointer_left(p, specs.precision);
	else
		len = put_pointer_left(p, specs.precision);
	return (len);
}
