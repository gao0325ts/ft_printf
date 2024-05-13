/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_or_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:44:12 by stakada           #+#    #+#             */
/*   Updated: 2024/05/13 21:09:06 by stakada          ###   ########.fr       */
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
	print_decimal(specs.precision, num, len);
	if (*len < 0)
		return ;
	print_spaces(*len, specs.width, len);
}

void	put_dec_right_2(t_spec specs, int num, int *len, int output_len)
{
	int digits;
	
	digits = count_digits(num);
	if (specs.flags & PREC_FLAG)
	{
		print_spaces(digits, count_padded_len(specs, digits), len);
		if (*len < 0)
			return ;
	}
	else
	{
		while (output_len++ < specs.width)
		{
			if (write(FD, " ", 1) < 0)
			{
				(*len) = -1;
				return ;
			}
		}
		print_symbol(specs.flags, num, len);
		if (*len < 0)
			return ;
		while (count_digits(num) < specs.precision--)
		{
			if (write(FD, "0", 1) < 0)
			{
				(*len) = -1;
				return ;
			}
			(*len)++;
		}
	}
	print_decimal(specs.precision, num, len);
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
	else if (specs.flags & FLAG_ZERO)
		put_dec_right_1(specs, num, &len);
	else
		put_dec_right_2(specs, num, &len, check_output_len(specs, num));
	return (len);
}
