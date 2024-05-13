/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:34:21 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 13:30:00 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hex_left(unsigned long long num, t_spec specs, int *len)
{
	print_prefix(specs, len);
	if (*len < 0)
		return ;
	print_zero_paddings(count_digits_hex(num), specs.precision, len);
	if (*len < 0)
		return ;
	print_hexadecimal(num, specs.flags & IS_X_UPPER, len);
	if (*len < 0)
		return ;
	print_spaces(*len, specs.width, len);
}

void	put_hex_right_1(unsigned long long num, t_spec specs, int *len)
{
	print_spaces(count_padded_len(specs, count_digits_hex(num)), specs.width,
		len);
	if (*len < 0)
		return ;
	print_prefix(specs, len);
	if (*len < 0)
		return ;
	print_zero_paddings(check_digits_hex(num), specs.precision, len);
	if (*len < 0)
		return ;
	print_hexadecimal(num, specs.flags & IS_X_UPPER, len);
}

void	put_hex_right_2(unsigned long long num, t_spec specs, int *len)
{
	if (specs.flags & FLAG_ZERO)
	{
		print_zero_paddings(count_digits_u(num), specs.width, len);
		if (*len < 0)
			return ;
		print_prefix(specs, len);
		if (*len < 0)
			return ;
	}
	else
	{
		print_spaces(count_digits_u(num), specs.width, len);
		if (*len < 0)
			return ;
		print_prefix(specs, len);
		if (*len < 0)
			return ;
	}
	print_hexadecimal(num, specs.flags & IS_X_UPPER, len);
}

int	ft_printf_x(t_spec specs, va_list args)
{
	unsigned long long	x;
	int					len;

	x = va_arg(args, unsigned long long);
	len = 0;
	if (!(specs.flags & FLAG_HASH || specs.flags & FLAG_HYPHEN
			|| specs.flags & FLAG_ZERO || specs.flags == 0))
		return (-1);
	if (specs.flags & FLAG_HYPHEN)
		put_hex_left(x, specs, &len);
	else if (specs.flags & PREC_FLAG)
		put_hex_right_1(x, specs, &len);
	else
		put_hex_right_2(x, specs, &len);
	return (len);
}
