/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:34:21 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 08:53:06 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hex_left(unsigned long long num, t_spec specs, int *len)
{
	print_zero_paddings(check_digits_hex(num, specs.precision), specs.precision, len);
}

void	put_hex_right(unsigned long long num, t_spec specs, int *len)
{
	
}

int	ft_printf_x(t_spec specs, va_list args)
{
	unsigned long long x;
	int len;

	x = va_arg(args, unsigned long long);
	len = 0;
	if (!(specs.flags & FLAG_HASH || specs.flags & FLAG_HYPHEN || specs.flags & FLAG_ZERO || specs.flags == 0))
		return (-1);
	if (specs.flags & FLAG_HYPHEN)
		put_hex_left(x, specs, &len);
	else
		put_hex_right(x, specs, &len);
	return (len);
}

// print_hexadecimal(, specs.flags & IS_X_UPPER)