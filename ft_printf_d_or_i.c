/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_or_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:44:12 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 22:26:37 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_symbol(int flags, int num, int *len)
{
	if (num < 0)
		(*len) = write(FD, "-", 1);
	else
	{
		if (flags & FLAG_PLUS)
			(*len) = write(FD, "+", 1);
		if (flags & FLAG_SPACE)
			(*len) = write(FD, " ", 1);
	}
}

void	put_dec_left(t_spec specs, int num, int *len)
{
	print_symbol(specs.flags, num, len);
	if (*len < 0)
		return ;
	print_zero_paddings(count_digits(num), specs.precision, len);
	if (*len < 0)
		return ;
	print_decimal(num, len);
	if (*len < 0)
		return ;
	print_spaces(*len, specs.width, len);
}

void	put_dec_right_1(t_spec specs, int num, int *len)
{
	int	digits;

	digits = count_digits(num);
	print_spaces(digits, count_padded_len(specs, digits, num < 0), len);
	if (*len < 0)
		return ;
	print_symbol(specs.flags, num, len);
	if (*len < 0)
		return ;
	print_zero_paddings(digits, specs.precision, len);
	if (*len < 0)
		return ;
	print_decimal(num, len);
}

void	put_dec_right_2(t_spec specs, int num, int *len)
{
	if (specs.flags & FLAG_ZERO)
	{
		print_symbol(specs.flags, num, len);
		if (*len < 0)
			return ;
		print_zero_paddings(count_padded_len(specs, count_digits(num), num < 0),
			specs.width, len);
	}
	else
	{
		print_spaces(count_padded_len(specs, count_digits(num), num < 0),
			specs.width, len);
		if (*len < 0)
			return ;
		print_symbol(specs.flags, num, len);
	}
	if (*len < 0)
		return ;
	print_decimal(num, len);
}

int	ft_printf_d_or_i(t_spec specs, va_list args)
{
	int	num;
	int	len;

	num = va_arg(args, int);
	len = 0;
	if (specs.flags & FLAG_HASH)
		return (-1);
	if (specs.flags & FLAG_HYPHEN)
		put_dec_left(specs, num, &len);
	else if (specs.flags & PREC_FLAG)
		put_dec_right_1(specs, num, &len);
	else
		put_dec_right_2(specs, num, &len);
	return (len);
}
